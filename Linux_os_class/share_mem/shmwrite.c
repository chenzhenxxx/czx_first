#include<stdio.h>
#include<string.h>
#include<sys/shm.h>
#include"shmdata.h"
int main()
{
    int running =1;
    void *shm =NULL;
    struct shrared_use_st *shared=NULL;
    char buffer[BUFSIZ+1];
    int shmid;
    shmid = shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);
    if(shmid==-1)
    {
        fprintf(stderr,"shmget fail\n");
        exit(-1);
    }
    shm = shmat(shmid,(void*)0,0);
    if(shm == (void*)-1)
    {
        fprintf(stderr,"shmat fail\n");
        exit(-1);
    }
    
}