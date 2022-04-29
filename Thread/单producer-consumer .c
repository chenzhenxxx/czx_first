#include<stdio.h>
#include<string.h>
#include<pthread.h>
pthread_cond_t cond;
pthread_mutex_t mutex;
int num=0;
#define THREAD_MAX 10
// Single-producer , single-consumer Queue
struct SPSCQueue{
    int value;
    struct SPSCQueue * next;

}typedef SPSCQueue;
SPSCQueue *head;
SPSCQueue *tail;

SPSCQueue *SPSCQueueInit();
void SPSCQueuePush(void *arg);
void *SPSCQueuePop(SPSCQueue *pool);
void SPSCQueueDestory(SPSCQueue *pool);

void SPSCQueueDestory(SPSCQueue *pool)
{
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
     while(pool->next)
     {   SPSCQueue *q;
         q=pool;
         free(q);
         pool=pool->next;

     }
}
SPSCQueue *SPSCQueueInit()
{
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&cond,NULL);
    head=NULL;
    tail=NULL;

}
void *SPSCQueuePop(SPSCQueue *pool)
{
   while(1)
    {
        if(num<THREAD_MAX)
         {
            pthread_mutex_lock(&mutex);
            SPSCQueue *p=(SPSCQueue*)malloc(sizeof(SPSCQueue));
            p->value=rand()%1000;
            p->next=head;
            printf("producer--->%d\n",p->value);
            head=p;
            num++;
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&cond);

         }
         else
         {
             printf("already full\n");
         }
         sleep(rand()%3);
    }
}
void SPSCQueuePush(void *arg)
{
    while(1)
    {
        pthread_mutex_lock(&mutex);
        if(head==NULL)
         {
             pthread_cond_wait(&cond,&mutex);
         }
         num--;
         tail=head;
           printf("consumer--->%d\n",tail->value);
         head=tail->next;
         free(tail);
         tail=NULL;
         pthread_mutex_unlock(&mutex);
         sleep(rand()%3);
    }
}
int main()
{  SPSCQueue *pool;
   SPSCQueueInit();
   pthread_t pid,cid;
   srand(time(NULL));//是随机数发生器的初始化函数
   int ret;
   ret=pthread_create(&pid,NULL,(void*)SPSCQueuePop,NULL);
    if(ret!=0)
     {
         printf("Error:pthread_create producter!\n");

     }
    ret=pthread_create(&cid,NULL,(void*)SPSCQueuePush,NULL);
    if(ret!=0)
     {
         printf("Error:pthread_create producter!\n");
         
     }
      pthread_join(pid, NULL);                      
      pthread_join(cid, NULL);  
      SPSCQueueDestory(pool); 
}





