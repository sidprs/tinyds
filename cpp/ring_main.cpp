#include <iostream>
#include <thread>

int main() {
    RingBuffer<int> rb(5);
    
    // Producer thread
    std::thread producer([&rb]() {
        for (int i = 0; i < 10; ++i) {
            rb.push(i);
            std::cout << "Pushed: " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
    
    // Consumer thread
    std::thread consumer([&rb]() {
        for (int i = 0; i < 10; ++i) {
            int val = rb.pop();
            std::cout << "Popped: " << val << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(150));
        }
    });
    
    producer.join();
    consumer.join();
    
    return 0;
}
