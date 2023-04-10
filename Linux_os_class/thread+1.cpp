// #include <stdio.h>
// #include <pthread.h>

// int x = 1;

// void *P1(void *arg) {
//     // 在P1中对x加1
//     x = x + 1;
//     return NULL;
// }

// void *P2(void *arg) {
//     // 在P2中对x加1
//     x = x + 1;
//     return NULL;
// }

// int main() {
//     pthread_t tid_P1, tid_P2;
//     // 创建线程P1和P2
//     pthread_create(&tid_P1, NULL, P1, NULL);
//     pthread_create(&tid_P2, NULL, P2, NULL);
//     // 等待P1和P2执行完
//     pthread_join(tid_P1, NULL);
//     pthread_join(tid_P2, NULL);
//     // 打印x的值
//     printf("final value of x is %d\n", x);
//     return 0;
// }
#include <iostream>
#include <thread>
#include <chrono>

volatile int count = 0; // 共享变量

void increment() {
    for(int i = 0; i < 10000; i++) {
        count++;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Final count: " << count << std::endl;

    return 0;
}