//main.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include "pron_c.h"

#define N 10 // 缓冲区大小
#define M 8 // 线程数量

sem_t space, prod, sinn,sout;
int Buffer[N]; // 缓冲区数组
int in = 0;    
int out = 0;   

int buff[M] = {0};  

sem_t empty_sem;
sem_t full_sem; 
pthread_mutex_t mutex;

void *producer(void *p)
{
    while(1)
    {
        sem_wait(&space); // 如果缓冲区已满，则阻塞等待可用空间
        sem_wait(&sinn);  // 加锁，保证对缓冲区的操作互斥

        printf("Put a product into Buffer%d\n", in);
        Buffer[in] = 1;    // 往缓冲区添加数据
        in = (in + 1) % N; // 更新下标，循环利用缓冲区

        sem_post(&prod); // 发出“可以消费”的信号，增加计数器
        sem_post(&sinn); // 解锁缓冲区
    }
    return NULL;
}

void *consumer(void *p)
{
    while(1)
    {
        sem_wait(&prod); // 如果没有可消费的产品，则阻塞等待
        sem_wait(&sout); // 加锁，保证对缓冲区的操作互斥

        printf("Gets a product in Buffer%d\n", out);
        Buffer[out] = 0;     // 从缓冲区取出数据
        out = (out + 1) % N; // 更新下标，循环利用缓冲区

        sem_post(&space); // 发出“可以生产”的信号，增加计数器
        sem_post(&sout);  // 解锁缓冲区
    }
    return NULL;
}

void sem_mutex_dead()
{
    sem_destroy(&space); // 销毁信号量
    sem_destroy(&prod);
    sem_destroy(&sinn);
    sem_destroy(&sout);
}

void sem_mutex_init()
{
    /*
     *semaphore initialize
     */
    sem_init(&space, 0, N); // 初始化空闲空间的信号量
    sem_init(&prod, 0, 0); // 初始化“可消费产品数量”的信号量
    sem_init(&sinn, 0, 1); // 初始化缓冲区的互斥锁
    sem_init(&sout, 0, 1); 
    
}


