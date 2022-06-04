#include<iostream>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>
#define NUM 5
int queue[NUM];
sem_t com,prc;
using namespace std;
void * producer(void *arg)
{
     int i=0;
     while(1)
     {
         sem_wait(&com);
         
         queue[i]=rand()%1000+1;
         printf("-PROC ---%d\n",queue[i]);
         sem_post(&prc);
         i=(i+1)%NUM;
         sleep(rand()%1);
     }
}
void * consumer(void *arg)
{
     int i=0;
     while(1)
     {
         sem_wait(&prc);
         printf("-Consum ---%d\n",queue[i]);
         queue[i]=0;
         sem_post(&com);
         i=(i+1)%NUM;
         sleep(rand()%3);
     }
}
int main()
{
    pthread_t pid,tid;
    sem_init(&com,0,NUM);
    sem_init(&prc,0,0);

    pthread_create(&pid,NULL,producer,NULL);
     pthread_create(&tid,NULL,consumer,NULL);

     pthread_join(pid,NULL);
     pthread_join(tid,NULL);
     return 0;
}