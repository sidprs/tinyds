#include <vector>
#include <mutex>
#include <condition_variable>
#include <stdexcept>

template<typename T>
class RingBuffer {
private:
    std::vector<T> buffer;
    size_t capacity;
    size_t head;   // next write position
    size_t tail;   // next read position
    size_t count;  // number of items (distinguishes full from empty)
    
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
        
        // Wait until buffer is not full (use WHILE for spurious wakeups)
        not_full.wait(lock, [this]() { return count < capacity; });
        
        // Add item
        buffer[head] = item;
        head = (head + 1) % capacity;  // Wrap around
        ++count;
        
        // Notify consumer that buffer is not empty
        not_empty.notify_one();
    }
    
    T pop() {
        std::unique_lock<std::mutex> lock(mtx);
        
        // Wait until buffer is not empty
        not_empty.wait(lock, [this]() { return count > 0; });
        
        // Remove item
        T item = buffer[tail];
        tail = (tail + 1) % capacity;  // Wrap around
        --count;
        
        // Notify producer that buffer is not full
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
