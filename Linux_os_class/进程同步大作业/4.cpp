#include<mutex>
#include<condition_variable>
#include<queue>
#include<unistd.h>

// 定义tasK_struct结构
struct tasK_struct {
    // process_id表示进程id
    int process_id;
};

class RecordSemaphore {

private:
    std::mutex mutex_lock;              // 互斥锁
    std::queue<tasK_struct> task_queue; // 进程等待队列
    int count;                          // 计数器
    std::condition_variable condition;  // 条件变量

public:

    // 构造函数，初始化计数器和条件变量
    RecordSemaphore(int initial_count): count(initial_count) {}

    // wait()操作
    void wait() {
        std::unique_lock<std::mutex> lock(mutex_lock);
        count--;
        if (count < 0) {  //没有可用资源
            tasK_struct task = { .process_id = getpid() };
            task_queue.push(task);   // 将进程加入等待队列
            condition.wait(lock);  // 调用 condition.wait() 函数阻塞它们
        }
    }

    // signal()操作
    void signal() {
        std::unique_lock<std::mutex> lock(mutex_lock);
        count++;
        if (count <= 0) {  //有等待的进程需要唤醒
            condition.notify_one(); // 通知一个等待进程
            task_queue.pop();       // 将等待队列中的进程取出
        }
    }

};


// 在这里，我们使用了`std::mutex`(互斥锁)、`std::condition_variable`(条件变量)和`std::queue`(队列)来实现记录型信号量的`wait()`和`signal()`操作。

// 在`wait()`操作中，我们首先对计数器进行减1操作。如果计数器小于0，则表示当前没有资源可用，需要将进程加入等待队列，并且调用`condition.wait(lock)`函数阻塞当前线程，并释放互斥锁。

// 在`signal()`操作中，我们首先对计数器进行加1操作。如果计数器小于等于0，则表示有进程正在等待资源，我们取出等待队列中的一个进程，并且通过`condition.notify_one()`函数通知该进程可以继续执行了。

// 这样，就完成了记录型信号量wait()和signal()操作的实现。