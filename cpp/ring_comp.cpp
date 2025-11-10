// ring_buffer_complete.cpp

/*
PRODUCER THREAD              BUFFER              CONSUMER THREAD
┌─────────────┐            ┌───────┐            ┌─────────────┐
│   while(i<10)│           │ [0]   │            │  while(i<10) │
│   {         │            │ [1]   │            │  {          │
│    push(i)  │ ────────→  │ [2]   │ ────────→  │   pop()     │
│    print    │            │ [3]   │            │   print     │
│    sleep    │            │ [4]   │            │   sleep     │
│   }         │            └───────┘            │  }          │
└─────────────┘            capacity=5           └─────────────┘
      ↓                                               ↓
runs every 100ms                              runs every 150ms


*/


#include <vector>
#include <mutex>
#include <condition_variable>
#include <stdexcept>
#include <iostream>
#include <thread>
#include <chrono>

template<typename T>
class RingBuffer {
private:
    std::vector<T> buffer;
    size_t capacity;
    size_t head;
    size_t tail;
    size_t count;
    
    std::mutex mtx;
    std::condition_variable not_full;
    std::condition_variable not_empty;

public:
    explicit RingBuffer(size_t cap) 
        : capacity(cap), head(0), tail(0), count(0) {
        if (cap == 0) throw std::invalid_argument("Capacity must be > 0");
        buffer.resize(capacity);
    }
    
    void push(const T& item) {
        std::unique_lock<std::mutex> lock(mtx);
        not_full.wait(lock, [this]() { return count < capacity; });
        
        buffer[head] = item;
        head = (head + 1) % capacity;
        ++count;
        
        not_empty.notify_one();
    }
    
    T pop() {
        std::unique_lock<std::mutex> lock(mtx);
        not_empty.wait(lock, [this]() { return count > 0; });
        
        T item = buffer[tail];
        tail = (tail + 1) % capacity;
        --count;
        
        not_full.notify_one();
        
        return item;
    }
    
    bool isEmpty() const {
        std::lock_guard<std::mutex> lock(mtx);
        return count == 0;
    }
    
    bool isFull() const {
        std::lock_guard<std::mutex> lock(mtx);
        return count == capacity;
    }
};

int main() {
    RingBuffer<int> rb(5);
    
    std::thread producer([&rb]() {
        for (int i = 0; i < 10; ++i) {
            rb.push(i);
            std::cout << "Pushed: " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    });
    
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
