#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <queue>
#include <unistd.h>

using namespace std;

#define THREAD_NUM 10

// 定义互斥锁
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// 定义任务队列
queue<int> task_queue;

void* worker(void* arg) {
    // 获取线程 ID
    pthread_t tid = pthread_self();

    // 不断从任务队列中取任务，直到队列为空时退出循环
    while (true) {
        int task;
        // 加锁，保证线程安全
        pthread_mutex_lock(&mutex);
        if (!task_queue.empty()) {  // 判断队列是否为空
            // 取出队头元素，并弹出
            task = task_queue.front();
            task_queue.pop();
            printf("Thread %lu got task %d\n", tid, task);

            // 计数器自增
            static int count = 0;
            ++count;
            printf("Task count is: %d\n", count);
        }
        else {
            // 队列为空时解锁并退出循环
            pthread_mutex_unlock(&mutex);
            break;
        }
        // 解锁
        pthread_mutex_unlock(&mutex);

        // 模拟处理任务的时间
        sleep(rand() % 3 + 1);
    }

    printf("Thread %lu exited\n", tid);
    return NULL;
}

int main() {
    srand(time(NULL));

    // 初始化任务队列
    for (int i = 0; i < 100; ++i) {
        task_queue.push(i);
    }

    // 创建多个子线程来处理任务
    pthread_t threads[THREAD_NUM];
    for (int i = 0; i < THREAD_NUM; ++i) {
        pthread_create(&threads[i], NULL, worker, NULL);
    }

    // 等待所有子线程执行完毕
    for (int i = 0; i < THREAD_NUM; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("All threads exited\n");
    return 0;
}
