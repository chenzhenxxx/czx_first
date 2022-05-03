#include<stdio.h>
#include<string.h>
#include<pthread.h>
pthread_cond_t cond;
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
    pthread_cond_destroy(&cond);
    free(pool->q);
    free(pool);
    
}
SPSCQueue *SPSCQueueInit(int capacity)
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    SPSCQueue * pool=(SPSCQueue *)malloc(sizeof(SPSCQueue));
    (pool->q)=(int *)malloc(sizeof(int)*capacity);
    pool->num=0;
    memset(pool->q,0,sizeof(pool->q));
    return pool;


}
void *SPSCQueuePop(SPSCQueue *pool)
{
   while(1)
    {
        if(pool->num<THREAD_MAX)
         {
            pthread_mutex_lock(&mutex);
            pool->q[(pool->num)]=rand()%1000;
            printf("producer--->%d\n",pool->q[pool->num]);
            (pool->num)++;
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&cond);

         }
         else
         {
             printf("already full\n");
         }
         sleep(rand()%2);
    }
}
void SPSCQueuePush(SPSCQueue *pool, void *s)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(pool->num==0)
         {
             pthread_cond_wait(&cond,&mutex);
         }
         
           (pool->num)--;
           printf("consumer--->%d\n",pool->q[pool->num]);
            
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
   ret=pthread_create(&pid,NULL,(void*)SPSCQueuePop,pool);
    if(ret!=0)
     {
         printf("Error:pthread_create producter!\n");

     }
    ret=pthread_create(&cid,NULL,(void*)SPSCQueuePush,pool);
    if(ret!=0)
     {
         printf("Error:pthread_create producter!\n");
         
     }
      pthread_join(pid, NULL);                      
      pthread_join(cid, NULL);  
      SPSCQueueDestory(pool); 
}





