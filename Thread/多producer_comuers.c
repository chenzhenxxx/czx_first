#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_cond_t cond;
pthread_mutex_t mutex;
pthread_t pid,cid;
#define PTHREAD_MAX 10

typedef struct MPMCQueue {
    
    int value;
    struct MPMCQueue *next;
}  MPMCQueue;
MPMCQueue *head;
MPMCQueue *tail;
int num=0;
MPMCQueue *MPMCQueueInit(int threadNumber);
void MPMCQueuePush(MPMCQueue *pool, void *s);
void *MPMCQueuePop(MPMCQueue *pool);
void MPMCQueueDestory(MPMCQueue *pool);
void MPMCQueueDestory(MPMCQueue *pool)
{
  pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
     while(pool->next)
     {   MPMCQueue *q;
         q=pool;
         free(q);
         pool=pool->next;

     }
}
void MPMCQueuePush(MPMCQueue *pool, void *s)
{     
     while(1)
    {   MPMCQueue *q;
        pthread_mutex_lock(&mutex);
        while(head==NULL)
        {
            pthread_cond_wait(&cond,&mutex);
        }
        q=head;
        printf("comsumer %d\n",q->value);
        num--;
        head=q->next;
        free(q);
        pthread_mutex_unlock(&mutex);
        sleep(rand()%5);


    }
}
void *MPMCQueuePop(MPMCQueue *pool)
{
    while(1)
     {
         
          if(num<PTHREAD_MAX)
           {   pthread_mutex_lock(&mutex);
               MPMCQueue *p=(MPMCQueue *)malloc(sizeof(MPMCQueue));
               p->value=rand()%1000+2;
               printf("producter——————————————————>%d\n", p->value);
               p->next=head;
               head=p;
               num++;
               pthread_mutex_unlock(&mutex);
               pthread_cond_signal(&cond);
            
           }
           else
           printf("max\n");
           sleep(rand()%5);
     }
}
MPMCQueue *MPMCQueueInit(int threadNumber)
{   
     MPMCQueue * pool=NULL;
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    head=NULL;
    tail=NULL;
    for(int i=0;i<threadNumber;i++)
    {   int ret;
        ret=pthread_create(&pid,NULL,MPMCQueuePop,(MPMCQueue *)pool);
        if(ret!=0)
         {
             printf("Error:pthread_create m%d\n",i);
         }
    }
    for(int i=0;i<threadNumber;i++)
    {   int ret;
        ret=pthread_create(&cid,NULL,MPMCQueuePush,(MPMCQueue *)pool);
        if(ret!=0)
         {
             printf("Error:pthread_create c%d\n",i);
         }
    }
    
}
int main()
{  MPMCQueue *pool;
int n;
scanf("%d",&n);
   MPMCQueueInit(n);
   srand(time(NULL));//是随机数发生器的初始化函数
      pthread_join(pid, NULL);                      
      pthread_join(cid, NULL);  
      MPMCQueueDestory(pool); 
}





