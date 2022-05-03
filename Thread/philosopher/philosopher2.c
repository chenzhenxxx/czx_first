//一次最多允许四个哲学家竞争
#include<stdio.h>
#include<pthread.h>
# include <semaphore.h>
sem_t pthread_kz[5];
sem_t count;
pthread_mutex_t mutex;
void * zxj(void *arg)
{
    int i=(int)arg;
    int left,right;
    if(i==4)
    {
      left=i;
      right=0;
    }
    else
    {
        left=i;
        right=i+1;
    }
      while(1)
      {   sleep(1); //思考
           sem_wait(&count);
           
          sem_wait(&pthread_kz[left]);
          printf("philosopher %d fetches chopstick %d\n",i,left);
          sem_wait(&pthread_kz[right]);
           printf("philosopher %d fetches chopstick %d\n",i,right);
           printf("philosopher %d is eating\n",i);

           sleep(2);
        
           sem_post(&pthread_kz[right]);
            printf("philosopher %d release chopstick %d\n",i,right);
           sem_post(&pthread_kz[left]); 
           printf("philosopher %d release chopstick %d\n",i,left);
           sem_post(&count);
      }
}
int main()
{
    pthread_t pid[5];
    pthread_mutex_init(&mutex,NULL);
    sem_init(&count,0,4);
    for(int i=0;i<5;i++)
    {
        sem_init(&pthread_kz[i],0,1);
        pthread_create(&pid[i],NULL,zxj,(void *)i);

    }
    for(int i=0;i<5;i++)
    {
        pthread_join(pid[i],NULL);
    }
    return 0;
}
