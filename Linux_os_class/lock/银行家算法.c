#include <stdio.h>
#include <stdbool.h>

#define NUM_RESOURCES 3
#define NUM_PROCESSES 3

int available[NUM_RESOURCES] = {4, 4, 4}; // 可用资源
int max[NUM_PROCESSES][NUM_RESOURCES] = { // 每个进程最大的需要量
    {2, 2, 3},
    {1, 3, 1},
    {3, 2, 1}
};
int allocation[NUM_PROCESSES][NUM_RESOURCES] = { // 每个进程分配的资源数
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}
};
int need[NUM_PROCESSES][NUM_RESOURCES]; // 每个进程还需要的资源数

void calculate_need() {
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        for (int j = 0; j < NUM_RESOURCES; ++j) {
            need[i][j] = max[i][j] - allocation[i][j]; // 计算每个进程还需要的资源数
        }
    }
}

bool is_safe_state(int request[NUM_RESOURCES], int process) {
    int work[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        work[i] = available[i]; // 初始化可用资源
    }

    int finish[NUM_PROCESSES] = {0}; // 各进程完成状态

    // 执行安全性检查，直到所有进程执行完
    bool found;
    do {
        found = false;
        for (int i = 0; i < NUM_PROCESSES; ++i) {
            if (finish[i] == 0) { // 如果进程未执行完
                bool can_execute = true;
                for (int j = 0; j < NUM_RESOURCES; ++j) { // 检查该进程所需的所有资源是否都可用
                    if (need[i][j] > work[j]) {
                        can_execute = false;
                        break;
                    }
                }
                if (can_execute) { // 如果该进程所需的所有资源都可用
                    for (int j = 0; j < NUM_RESOURCES; ++j) { // 更新可用资源
                        work[j] += allocation[i][j];
                    }
                    finish[i] = 1; // 标记该进程已执行完
                    found = true;
                }
            }
        }
    } while (found);

    // 检查进程执行状态，如果有进程未执行完，则状态不安全
    for (int i = 0; i < NUM_PROCESSES; ++i) {
        if (finish[i] == 0) {
            return false; // 不安全状态
        }
    }

    // 如果请求成功，预分配资源
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        available[i] -= request[i];
        allocation[process][i] += request[i];
        need[process][i] -= request[i];
    }

    return true; // 安全状态
}

void release_resources(int process) { // 释放进程已经分配的所有资源
    for (int i = 0; i < NUM_RESOURCES; ++i) {
        available[i] += allocation[process][i];
        allocation[process][i] = 0;
        need[process][i] = 0;
    }
}

int main() {
    calculate_need(); // 计算每个进程还需要的资源数

    // 第一个进程请求一些资源
    int request[NUM_RESOURCES] = {2, 1, 0};
    int process = 0;
    if (is_safe_state(request, process)) { // 如果请求成功且不会导致不安全状态
        printf("Request granted. Safe state achieved.\n");
    } else {
        printf("Request denied. Unsafe state. Aborting.\n");
        return 1;
    }

    // 第二个进程请求一些资源
    int request2[NUM_RESOURCES] = {1, 2, 1};
    int process2 = 1;
    if (is_safe_state(request2, process2)) {
        printf("Request granted. Safe state achieved.\n");
    } else {
        printf("Request denied. Unsafe state. Aborting.\n");
        release_resources(process); // 释放第一个进程已经分配的资源
        return 2;
    }

    // 第三个进程请求一些资源
    int request3[NUM_RESOURCES] = {0, 0, 1};
    int process3 = 2;
    if (is_safe_state(request3, process3)) {
        printf("Request granted. Safe state achieved.\n");
    } else {
        printf("Request denied. Unsafe state. Aborting.\n");
        release_resources(process); // 释放第一个进程已经分配的资源
        release_resources(process2); // 释放第二个进程已经分配的资源
        return 3;
    }

    // 所有进程释放资源
    release_resources(process);
    release_resources(process2);
    release_resources(process3);

    printf("All requests granted. All resources released. End of program.\n");
    return 0;
}