#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> count(0); // 原子变量

void increment() {
    for(int i = 0; i < 100000; i++) {
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