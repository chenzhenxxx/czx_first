#include<stdio.h>
#include<string.h>
#include<pthread.h>
pthread_cond_t cond;
pthread_mutex_t mutex;
int THREAD_MAX;
// Single-producer , single-consumer Queue
struct MPMCQueue
{
    int *q;
    int num;

}typedef MPMCQueue;


MPMCQueue *MPMCQueueInit(int capacity);
void *MPMCQueuePop(MPMCQueue *pool);
void MPMCQueuePush(MPMCQueue *pool, void *s);
void MPMCQueueDestory(MPMCQueue *pool);

void MPMCQueueDestory(MPMCQueue *pool)
{
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    free(pool->q);
    free(pool);
    
}
MPMCQueue *MPMCQueueInit(int capacity)
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    MPMCQueue * pool=(MPMCQueue *)malloc(sizeof(MPMCQueue));
    (pool->q)=(int *)malloc(sizeof(int)*capacity);
    pool->num=0;
    memset(pool->q,0,sizeof(pool->q));
    return pool;


}
void *MPMCQueuePop(MPMCQueue *pool)
{
   while(1)
    {
        if(pool->num<THREAD_MAX)
         {
            pthread_mutex_lock(&mutex);
            pool->q[(pool->num)%THREAD_MAX]=rand()%1000;
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
void MPMCQueuePush(MPMCQueue *pool, void *s)
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
{  MPMCQueue *pool;
    int n;
    scanf("%d",&n);
    THREAD_MAX=n;
   pool=MPMCQueueInit(n);
   pthread_t pid,cid;
   srand(time(NULL));//是随机数发生器的初始化函数
   int ret;
   ret=pthread_create(&pid,NULL,(void*)MPMCQueuePop,pool);
    if(ret!=0)
     {
         printf("Error:pthread_create producter!\n");

     }
    ret=pthread_create(&cid,NULL,(void*)MPMCQueuePush,pool);
    if(ret!=0)
     {
         printf("Error:pthread_create producter!\n");
         
     }
      pthread_join(pid, NULL);                      
      pthread_join(cid, NULL);  
      MPMCQueueDestory(pool); 
}





