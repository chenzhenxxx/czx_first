#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

int count = 0; // 共享变量
std::mutex mtx; // 互斥锁

void increment() {
    for(int i = 0; i < 10000; i++) {
        std::lock_guard<std::mutex> guard(mtx);
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