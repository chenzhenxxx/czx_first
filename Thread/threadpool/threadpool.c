#include "threadpool.h"
#include<pthread.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>
#define NUM 2  //
typedef struct Task
{
    void (*function)(void * arg);
    void *arg;
}Task;
typedef struct ThreadPool   //线程池结构
{
     //任务队列
     Task *Q;
     int  queuecapacity; //队列容量
     int  queuesize;  //当前任务个数
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
     pthread_mutex_t mutexpool; //线程池锁
     pthread_mutex_t mutexbusy; //专门锁BusyNum
     pthread_cond_t notfull;   
     pthread_cond_t notempty;
     int shutdown; //线程是否关闭



}ThreadPool;
ThreadPool *threadPoolCreate(int min,int max,int Capacity)  //创建线程函数
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
      {  printf("malloc threadID fail\n");
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
      pthread_cond_init(&pool->notfull,NULL)!=0) //初始化互斥锁和条件变量
      {
          printf("init error\n");
      }
      //创建线程
      pthread_create(&pool->managerID,NULL,manager,pool);  //创建管理者线程
      for(int i=0;i<min;i++)
      pthread_create(&pool->threadID[i],NULL,worker,pool); //消费者
      
      return pool;
    }while(0);

     //如果失败//

    //回收free
    if(pool&&pool->threadID)
    free(pool->threadID);
    if(pool&&pool->Q)
    free(pool->Q);
    if(pool)
    free(pool);
    return NULL;



}
void* worker(void* arg)  //消费者线程
{
    ThreadPool *pool =(ThreadPool*)arg;
    while(1)
    {
        pthread_mutex_lock(&pool->mutexpool);
      while(pool->queuesize==0&&!pool->shutdown)  //当前队列为空但是线程池没有关闭
     {     //阻塞
          pthread_cond_wait(&pool->notempty,&pool->mutexpool);
          if(pool->killNum!=0)
           {   pool->killNum--;
               if(pool->liveNum>pool->minNum)
               {   pool->liveNum--;
                   pthread_mutex_unlock(&pool->mutexpool); //在wait时上锁了
                   threadExit(pool);
               }
           }
     }
     if(pool->shutdown)
      {
          pthread_mutex_unlock(&pool->mutexpool);
          threadExit(pool);
      }
      //取出任务
     Task task;
    task.function=pool-> Q[pool->queuehead].function;
    task.arg=pool-> Q[pool->queuehead].arg;
    pool->queuehead=(pool->queuehead+1)%pool->queuecapacity;   //维护循环队列
    pool->queuesize--;
     
    pthread_cond_signal(&pool->notfull);  //唤醒生产者
    pthread_mutex_unlock(&pool->mutexpool);
    printf("pthread %ld start doing work\n",pthread_self());
    pthread_mutex_lock(&pool->mutexbusy);
    pool->busyNum++;
     pthread_mutex_unlock(&pool->mutexbusy);
     task.function(task.arg);
     free(task.arg);
     task.arg=NULL;
     printf("thread %ld end working..\n",pthread_self());
     pthread_mutex_lock(&pool->mutexbusy);
    pool->busyNum--;
     pthread_mutex_unlock(&pool->mutexbusy);


    



     
    }
}
void* manager(void* arg)
{
    ThreadPool * pool=(ThreadPool*)arg;
    while(!pool->shutdown)
     {
         sleep(3);
         pthread_mutex_lock(&pool->mutexpool);
          int queueNum=pool->queuesize; //获取任务个数
          int  liveNum=pool->liveNum;  //获取存活个数
        pthread_mutex_unlock(&pool->mutexpool);

        pthread_mutex_lock(&pool->mutexbusy);
          int busyNum=pool->busyNum;
        pthread_mutex_unlock(&pool->mutexbusy);

        //创建线程
         if(((liveNum-queueNum)<3)&&liveNum<pool->maxNum) //提前增加 如果工作任务与存活个数相差小于3并且存活个数小于最大线程数
          {
             pthread_mutex_lock(&pool->mutexpool);
             int cnt=0;
              for(int i=0;i<pool->maxNum&&cnt<NUM&&pool->liveNum<pool->maxNum;i++)
               {
                   if(pool->threadID[i]==0) //说明该线程没使用
                    {   pthread_create(&pool->threadID[i],NULL,worker,pool);
                        pool->liveNum++;
                        cnt++;
                    }

               }
             pthread_mutex_unlock(&pool->mutexpool);

          }

         //销毁线程

          else if(liveNum>2*busyNum&&liveNum>pool->minNum)
           {
               pthread_mutex_lock(&pool->mutexpool);
                pool->killNum=NUM;
                pthread_mutex_unlock(&pool->mutexpool);
                for(int i=0;i<NUM;i++)
                 {
                     pthread_cond_signal(&pool->notempty);
                 }

           }
     }
     return NULL;
}
void threadExit(ThreadPool* pool)  
{
    pthread_t tid=pthread_self();
    for(int i=0;i<pool->maxNum;i++)
     {
         if(pool->threadID[i]==tid) //找到要销毁的当前线程
          {
              pool->threadID[i]=0;
              printf("threadid exit called,%ld is exiting ..\n",tid);
          }
     }
     pthread_exit(NULL);
}
void threadPoolAdd(ThreadPool* pool, void(*func)(void*), void* arg) //添加任务 （生产者）
{
    if(pool->queuesize==pool->queuecapacity&&!pool->shutdown) //任务队列满了但是线程池没有关闭
    {
        pthread_cond_wait(&pool->notfull,&pool->mutexpool);

    }

    if(pool->shutdown)
     {
         pthread_mutex_unlock(&pool->mutexpool);  //因为wait的时候上锁了
         return;
     }
     pool->Q[pool->queuerear].function=func;
     pool->Q[pool->queuerear].arg=arg;
     pool->queuerear=(pool->queuerear+1)%pool->queuecapacity; //维护环形队列
     pool->queuesize++;
     pthread_cond_signal(&pool->notempty); //唤醒消费者
}
int threadPoolBusyNum(ThreadPool* pool)
{
    pthread_mutex_lock(&pool->mutexbusy);
    int busynum=pool->busyNum;
    pthread_mutex_unlock(&pool->mutexbusy);
    return busynum;
}
int threadPoolAliveNum(ThreadPool* pool)
{
    pthread_mutex_lock(&pool->mutexpool);
    int livenum=pool->liveNum;
    pthread_mutex_unlock(&pool->mutexpool);
    return livenum;
}
int threadPoolDestroy(ThreadPool* pool)  //摧毁当前线程
{
    if(pool==NULL)
    {
        return -1;
    }
    pool->shutdown=1; //关闭线程池

    pthread_join(pool->managerID,NULL);  //阻塞回收管理者
    for(int i=0;i<pool->liveNum;i++)
    {
        pthread_cond_signal(&pool->notempty);
    }
    if(pool->Q)
    {
        free(pool->Q);
    }
    if(pool->threadID)
    {
        free(pool->threadID);
    }
    pthread_mutex_destroy(&pool->mutexbusy);
     pthread_mutex_destroy(&pool->mutexpool);
      pthread_cond_destroy(&pool->notempty);
       pthread_cond_destroy(&pool->notfull);
       if(pool)
    free(pool);
    pool=NULL;
        
    return 0;
}
void function (void *arg)
{   int num=*(int *)arg;
    printf("thread %ld is working ,num=%d\n",pthread_self(),num);
    sleep(1);
}
int main()
{
    ThreadPool * pool =threadPoolCreate(3,10,100);
     for(int i=0;i<100;i++)
     {
         int * num=(int *)malloc(sizeof(int));
         *num+=i;
         threadPoolAdd(pool,function,num);
     }
     sleep(20);
     threadPoolDestroy(pool);
     return 0;
}