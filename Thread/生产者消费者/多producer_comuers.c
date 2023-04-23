#include<stdio.h>
#include<string.h>
#include<pthread.h>

/*
 * 条件变量和互斥锁，用于协调多个线程之间的同步问题。
 */
pthread_cond_t cond;
pthread_mutex_t mutex;

/*
 * 线程数量上限常量 THREAD_MAX 可以在程序运行时从外部传入，
 * 这里采用了全局变量的方式，方便后续函数的调用。
 */
int THREAD_MAX;


// Single-producer , single-consumer Queue
struct MPMCQueue
{
    int *q;     // 存储数据的队列指针
    int num;    // 队列中元素的数量

} typedef MPMCQueue;


/*
 * 此函数初始化队列，并且将其指针返回。
 * capacity 参数代表队列容量。
 */
MPMCQueue *MPMCQueueInit(int capacity);

/*
 * 生产者向队列中添加元素。
 * pool 参数是队列指针，s 参数是新添加的元素。
 */
void MPMCQueuePush(MPMCQueue *pool, void *s);

/*
 * 从队列中取出一个元素。
 * pool 参数是队列指针。
 */
void *MPMCQueuePop(MPMCQueue *pool);

/*
 * 销毁队列并释放资源。
 * pool 参数是队列指针。
 */
void MPMCQueueDestory(MPMCQueue *pool);



/*
 * 函数定义：
 * 初始化队列，并为队列申请空间。
 * 返回申请好的队列指针。
 */
MPMCQueue *MPMCQueueInit(int capacity)
{
    /*
     * 初始化互斥锁和条件变量。
     */
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    /*
     * 为队列申请存储空间，并初始化相关属性。
     */
    MPMCQueue * pool = (MPMCQueue *)malloc(sizeof(MPMCQueue));
    (pool->q) = (int *)malloc(sizeof(int) * capacity);
    pool->num = 0;
    memset(pool->q, 0, sizeof(pool->q));

    /*
     * 将初始化好的队列指针返回。
     */
    return pool;
}


/*
 * 函数定义：
 * 向队列中添加元素的过程。
 * 该函数可以被多个生产者线程同时调用。
 */
void MPMCQueuePush(MPMCQueue *pool, void *s)
{
   while(1)
    {
        /*
         * 判断队列是否已满，若未满则在互斥锁保护下执行以下操作：
         * - 在队列尾部添加一个新元素
         * - 将 num 加一
         * - 发送条件信号唤醒任意一个等待的消费者线程
         * - 解除互斥锁保护
         */
        if(pool->num < THREAD_MAX)
         {
            pthread_mutex_lock(&mutex);
            pool->q[(pool->num) % THREAD_MAX] = rand() % 1000;
            printf("producer--->%d\n", pool->q[pool->num]);
            (pool->num)++;
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&cond);
         }
         else
         {
             printf("already full\n");
         }
        
        /*
         * 生产者线程等待一定时间（0 到 2 秒之间的随机时间）后再次尝试添加新元素。
         */
         sleep(rand() % 3);
    }
}


/*
 * 函数定义：
 * 队列中取出一个元素的过程。
 * 该函数可以被多个消费者线程同时调用。
 */
void *MPMCQueuePop(MPMCQueue *pool)
{
    while(1)
    {
        /*
         * 在互斥锁保护下执行以下操作：
         * - 如果队列为空就等待条件信号唤醒
         * - 取出队列头部的一个元素
         * - 使用 num 值减一
         * - 输出当前获取的元素值
         * - 解除互斥锁保护
         */
        pthread_mutex_lock(&mutex);

        if(pool->num == 0)
         {
             pthread_cond_wait(&cond, &mutex);
         }

        (pool->num)--;
        printf("consumer--->%d\n", pool->q[pool->num]);

        pthread_mutex_unlock(&mutex);
        
        /*
         * 消费者线程等待一定时间（0 到 2 秒之间的随机时间）后再次尝试获取元素。
         */
         sleep(rand() % 3);
    }
}


/*
 * 函数定义：
 * 销毁队列，并且释放申请的所有资源。
 */
void MPMCQueueDestory(MPMCQueue *pool)
{
    /*
     * 销毁互斥锁和条件变量，并且释放队列中存储元素的空间。
     */
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    free(pool->q);

    /*
     * 最后，释放整个队列所占用的空间。
     */
    free(pool);
}


/*
 * 主函数入口，程序从这里开始执行。
 */
int main()
{  
    MPMCQueue *pool;

    /*
     * 从标准输入读取线程数量上限，作为生产者和消费者同时运行线程的最大数量。
     */
    int n;
    printf("please input have ? producer and comuers?\n");
    scanf("%d", &n);
    THREAD_MAX = n;

    /*
     * 创建多个子线程，其中一个作为生产者向队列中添加元素，其余线程都作为消费者从队列中取出元素。
     * 每个线程使用不同的 ID 和函数指针进行创建。
     */
    pool = MPMCQueueInit(n);
    pthread_t pid, cid;
    srand(time(NULL)); //是随机数发生器的初始化函数
    int ret;
    ret = pthread_create(&pid, NULL, (void *)MPMCQueuePush, pool);
    if(ret != 0)
     {
         printf("Error:pthread_create producter!\n");
     }

    for(int i = 0; i < n - 1; i++)
     {
        ret = pthread_create(&cid, NULL, (void *)MPMCQueuePop, pool);
        if(ret != 0)
         {
             printf("Error:pthread_create consumer! No.%d\n",i+1);
         }
     }

    /*
     * 等待子线程结束，销毁队列，释放资源。
     */
    pthread_join(pid, NULL);                      
    pthread_join(cid, NULL);  
    MPMCQueueDestory(pool); 
}
