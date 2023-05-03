#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t mutex2 = PTHREAD_MUTEX_INITIALIZER;

void* thread_func1(void* arg) {
    pthread_mutex_lock(&mutex1); // 获取mutex1
    printf("Thread 1 acquired mutex1.\n");
    sleep(1);
    pthread_mutex_lock(&mutex2); // 获取mutex2
    printf("Thread 1 acquired mutex2.\n");

    pthread_mutex_unlock(&mutex2); // 释放mutex2
    pthread_mutex_unlock(&mutex1); // 释放mutex1

    return NULL;
}

void* thread_func2(void* arg) {
    pthread_mutex_lock(&mutex2); // 获取mutex2
    printf("Thread 2 acquired mutex2.\n");
    sleep(1);
    pthread_mutex_lock(&mutex1); // 获取mutex1
    printf("Thread 2 acquired mutex1.\n");

    pthread_mutex_unlock(&mutex1); // 释放mutex1
    pthread_mutex_unlock(&mutex2); // 释放mutex2

    return NULL;
}

int main() {
    pthread_t tid1, tid2;

    pthread_create(&tid1, NULL, thread_func1, NULL);
    pthread_create(&tid2, NULL, thread_func2, NULL);

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);

    return 0;
}
