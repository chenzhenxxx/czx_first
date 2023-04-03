#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>  // pthread 库提供了支持线程的 API

#define NUM_THREADS 5  // 定义5个线程

void *thread_func(void *arg) {
    int tid = *((int *)arg);
    printf("Hello from thread %d\n", tid);
    pthread_exit(NULL);  // 线程退出
}

int main() {
    pthread_t threads[NUM_THREADS]; // 创建线程的数组
    int thread_args[NUM_THREADS];  // 为每个线程传入参数
    int i;

    // 创建线程
    for (i = 0; i < NUM_THREADS; i++) {
        thread_args[i] = i;
        if (pthread_create(&threads[i], NULL, thread_func, &thread_args[i]) != 0) {
            printf("error: pthread_create failed\n");
            exit(-1);
        }
    }

    // 等待线程结束
    for (i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            printf("error: pthread_join failed\n");
            exit(-1);
        }
    }
    return 0;
}