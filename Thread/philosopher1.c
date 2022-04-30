#include<stdio.h>
#include<pthread.h>
pthread_mutex_t pthread_kz[5];
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
          pthread_mutex_lock(&pthread_kz[left]); //拿左筷子 
          printf("philosopher %d fetches chopstick %d\n",i,left);
           if((pthread_mutex_trylock(&pthread_kz[right]))!=0)
           {
                  pthread_mutex_unlock(&pthread_kz[left]); 
                  continue;                                      
           }
           printf("philosopher %d fetches chopstick %d\n",i,right);
           printf("philosopher %d is eating\n",i);

           sleep(2);

           pthread_mutex_unlock(&pthread_kz[right]);
            printf("philosopher %d fetches chopstick %d\n",i,right);
          pthread_mutex_unlock(&pthread_kz[left]); 
           printf("philosopher %d fetches chopstick %d\n",i,left);
      }
}
int main()
{
    pthread_t pid[5];
    for(int i=0;i<5;i++)
    {
        pthread_mutex_init(&pthread_kz[i],NULL);
        pthread_create(&pid[i],NULL,zxj,(void *)i);

    }
    for(int i=0;i<5;i++)
    {
        pthread_join(pid[i],NULL);
    }
    return 0;
}
