#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
pthread_cond_t notFull;
pthread_cond_t notEmpty;
pthread_mutex_t mutex;
int THREAD_MAX;
// Single-producer , single-consumer Queue
struct SPSCQueue
{
    int *q;
    int num;

}typedef SPSCQueue;


SPSCQueue *SPSCQueueInit(int capacity);
void *SPSCQueuePop(SPSCQueue *pool);
void SPSCQueuePush(SPSCQueue *pool, void *s);
void SPSCQueueDestory(SPSCQueue *pool);

void SPSCQueueDestory(SPSCQueue *pool)
{
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&notEmpty);
    pthread_cond_destroy(&notFull);
    free(pool->q);
    free(pool);
    
}
SPSCQueue *SPSCQueueInit(int capacity)
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&notEmpty,NULL);
     pthread_cond_init(&notFull,NULL);
    SPSCQueue * pool=(SPSCQueue *)malloc(sizeof(SPSCQueue));
    (pool->q)=(int *)malloc(sizeof(int)*capacity);
    pool->num=0;
    memset(pool->q,0,sizeof(pool->q));
    return pool;


}
void SPSCQueuePush(SPSCQueue *pool, void *s) //生产者
{
   while(1)
    {   pthread_mutex_lock(&mutex);
        if(pool->num<THREAD_MAX)
         {
            
            pool->q[(pool->num)]=rand()%1000;
            printf("producer--->%d\n",pool->q[pool->num]);
            (pool->num)++;
           
            pthread_cond_signal(&notEmpty);

         }
         else
         {   
             printf("already full\n");
             pthread_cond_wait(&notFull,&mutex);
         }
          pthread_mutex_unlock(&mutex);
         sleep(rand()%2);
    }
}
void *SPSCQueuePop(SPSCQueue *pool)  //消费者
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(pool->num==0)
         {   
             pthread_cond_wait(&notEmpty,&mutex);
         }
         
           (pool->num)--;
           printf("consumer--->%d\n",pool->q[pool->num]);
           pthread_cond_signal(&notFull);
         pthread_mutex_unlock(&mutex);
         sleep(rand()%3);
    }
}
int main()
{  SPSCQueue *pool;
    int n;
    scanf("%d",&n);
    THREAD_MAX=n;
   pool=SPSCQueueInit(n);
   pthread_t pid,cid;
   srand(time(NULL));//是随机数发生器的初始化函数
   int ret;
   ret=pthread_create(&pid,NULL,(void*)SPSCQueuePush,pool);
    if(ret!=0)
     {
         printf("Error:pthread_create producter!\n");

     }
    ret=pthread_create(&cid,NULL,(void*)SPSCQueuePop,pool);
    if(ret!=0)
     {
         printf("Error:pthread_create producter!\n");
         
     }
      pthread_join(pid, NULL);                      
      pthread_join(cid, NULL);  
      SPSCQueueDestory(pool); 
}





