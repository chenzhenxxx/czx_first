#include "threadpool.h"
#include<pthread.h>
typedef struct Task
{
    void (*function)(void * arg);
    void *arg;
}Task;
typedef struct ThreadPool
{
     //任务队列
     Task *Q;
     int  queuecapacity; //队列容量
     int  queuesize;
     int queuehead; //队头存数据
     int queuerear; //队尾取数据
     //线程池
     pthread_t managerID; //管理者线程ID；
     pthread_t *threadID;  //不止一个所以先用指针；
     int minNum; //最小线程数量
     int maxNum; //最大线程数量
     int busyNum; //忙的线程
     int liveNum; //活的线程
     int killNum; //需要杀死的线程
     pthread_mutex_t mutexpool;
     pthread_mutex_t mutexbusy;
     pthread_cond_t notfull;
     pthread_cond_t notempty;
     int shutdown; //线程是否关闭



}ThreadPool;
ThreadPool *threadPoolCreate(int min,int max,int Capacity)
{
    //线程池
     ThreadPool * pool =(ThreadPool *)malloc(sizeof(ThreadPool));
    do
    {
   
    if(pool==NULL)
     {   printf("malloc threadpool fail\n");
         break;
     }

    pool->minNum=min;
    pool->maxNum=max;

    pool->threadID=(pthread_t *)malloc(sizeof(pthread_t)*max);
  if(pool->threadID==NULL)
   {
       break;
   }
   memset(pool->threadID,0,sizeof(pthread_t *)*max);
    //任务队列
      pool->Q=(Task *)malloc(sizeof(Task)*Capacity);
      pool->queuecapacity=Capacity;
      pool->queuesize=0;
      pool->queuehead=0;
      pool->queuerear=0;

      if(pool->Q==NULL)
      {
          break;
      }
      pool->killNum=0;
      pool->liveNum=min;
      pool->busyNum=0;
      pool->shutdown=0;
      if(pthread_mutex_init(&pool->mutexpool,NULL)!=0||
      pthread_mutex_init(&pool->mutexbusy,NULL)!=0||
      pthread_cond_init(&pool->notempty,NULL)!=0||
      pthread_cond_init(&pool->notfull,NULL)!=0)
      {
          printf("init error\n");
      }
      //创建线程
      pthread_create(&pool->managerID,NULL,manager,NULL);
      for(int i=0;i<min;i++)
      pthread_create(&pool->threadID[i],NULL,worker,NULL);
      
      return pool;
    }while(0);
    
    //回收free
    if(pool&&pool->threadID)
    free(pool->threadID);
    if(pool&&pool->Q)
    free(pool->Q);
    if(pool)
    free(pool);
    return NULL;



}
void* worker(void* arg)
{
    ThreadPool *pool =(ThreadPool*)arg;
    while(1)
    {
        pthread_mutex_lock(&pool->mutexpool);
    while(pool->queuesize==0&&!pool->shutdown)  //当前队列为空
     {     //阻塞
          pthread_cond_wait(&pool->notempty,&pool->mutexpool);
     }
     if(pool->shutdown)
      {
          pthread_mutex_unlock(&pool->mutexpool);
          pthread_exit(NULL);
      }
     Task task;
    task.function=pool-> Q[pool->queuehead].function;
    task.arg=pool-> Q[pool->queuehead].arg;
    pool->queuehead=(pool->queuehead+1)%pool->queuecapacity;   
    pool->queuesize--;
    pthread_mutex_lock(&pool->mutexbusy);
    pool->busyNum++;
     pthread_mutex_unlock(&pool->mutexbusy);
     task.function(task.arg);
     printf("thread %ld end working..\n");
     pthread_mutex_lock(&pool->mutexbusy);
    pool->busyNum--;
     pthread_mutex_unlock(&pool->mutexbusy);

    



     pthread_mutex_unlock(&pool->mutexpool);
    }
}