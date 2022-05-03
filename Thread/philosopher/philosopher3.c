//每个哲学家都用互斥量保护
#include<stdio.h>
#include<pthread.h>
# include <semaphore.h>
sem_t pthread_kz[5];
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
           
           pthread_mutex_lock(&mutex);
          sem_wait(&pthread_kz[left]);
          printf("philosopher %d fetches chopstick %d\n",i,left);
          sem_wait(&pthread_kz[right]);
           printf("philosopher %d fetches chopstick %d\n",i,right);
           printf("philosopher %d is eating\n",i);

           sleep(2);
           pthread_mutex_unlock(&mutex);
           sem_post(&pthread_kz[right]);
            printf("philosopher %d release chopstick %d\n",i,right);
           sem_post(&pthread_kz[left]); 
           printf("philosopher %d release chopstick %d\n",i,left);
      }
}
int main()
{
    pthread_t pid[5];
    pthread_mutex_init(&mutex,NULL);
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
