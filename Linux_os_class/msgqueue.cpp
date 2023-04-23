#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <pthread.h>
#include <sys/msg.h>

using namespace std;

// 定义消息结构体
struct message {
    long type; // 消息类型
    char data[1024]; // 消息内容
};

int msgid; // 消息队列ID
pthread_mutex_t mutex; // 互斥锁

// 生产者线程
void *producer(void *arg) {
    int count = 0;
    message msg;
    while (true) {
        // 生成消息
        msg.type = 1;
        memset(msg.data, 0, sizeof(msg.data));
        msg.data[0] = 'a' + count % 26;
        count++;
        // 加锁
        pthread_mutex_lock(&mutex);
        // 发送消息到队列
        if (msgsnd(msgid, &msg, sizeof(msg.data), IPC_NOWAIT) == -1) {
            cerr << "msgsnd error\n";
            exit(1);
        }
        cout << "Producer: " << msg.data << endl;
        // 解锁
        pthread_mutex_unlock(&mutex);
        usleep(500000); // 睡眠一段时间
    }
}

// 消费者线程
void *consumer(void *arg) {
    message msg;
    while (true) {
        // 加锁
        pthread_mutex_lock(&mutex);
        // 从队列中接收消息
        if (msgrcv(msgid, &msg, sizeof(msg.data), 1, IPC_NOWAIT) == -1) {
            cerr << "msgrcv error\n";
            sleep(1); // 如果没有消息，则睡眠一段时间再继续尝试
            continue;
        }
        cout << "Consumer: " << msg.data << endl;
        // 解锁
        pthread_mutex_unlock(&mutex);
        usleep(500000); // 睡眠一段时间
    }
}

// 主函数
int main() {
    pthread_t tid_producer, tid_consumer;
    // 创建消息队列
    msgid = msgget(IPC_PRIVATE, IPC_CREAT|0666);
    if (msgid == -1) {
        cerr << "msgget error\n";
        exit(1);
    }
    // 初始化互斥锁
    pthread_mutex_init(&mutex, NULL);
    // 创建生产者和消费者线程
    pthread_create(&tid_producer, NULL, producer, NULL);
    pthread_create(&tid_consumer, NULL, consumer, NULL);
    // 等待线程结束
    pthread_join(tid_producer, NULL);
    pthread_join(tid_consumer, NULL);
    // 删除消息队列
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        cerr << "msgctl error\n";
        exit(1);
    }
    // 销毁互斥锁
    pthread_mutex_destroy(&mutex);
    return 0;
}