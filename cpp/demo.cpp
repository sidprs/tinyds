#include <iostream>
#include <vector>
#include <atomic>
#include <mutex>
#include <shared_mutex>
#include <string>
#include <thread>

// ==========================================================
// Question 1: Thread-safe Counter
// Problem: increment() is not atomic. Multiple threads may corrupt count_.
// Task: Make thread-safe using mutex or atomic.
// ==========================================================
class Counter {
public:
    // Thread-safe increment using atomic
    void increment() {
        count_.fetch_add(1, std::memory_order_relaxed);
    }

    int get() const {
        return count_.load(std::memory_order_relaxed);
    }

private:
    std::atomic<int> count_{0};
    // Pseudo-code explanation:
    // atomic<int> ensures increment is done atomically without race.
    // fetch_add returns previous value, memory_order_relaxed is enough for simple counter.
};

// ==========================================================
// Question 2: Shared Vector Append
// Problem: push_back is not thread-safe. Multiple threads can crash.
// Task: Protect vector with a mutex.
// ==========================================================
class SafeVector {
public:
    void add(int value) {
        std::lock_guard<std::mutex> lock(mtx_);
        data_.push_back(value);
    }

    size_t size() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return data_.size();
    }

private:
    std::vector<int> data_;
    mutable std::mutex mtx_;
    // Pseudo-code:
    // Lock the mutex whenever accessing vector for push_back or size.
    // mutable allows size() const to lock the mutex.
};

// ==========================================================
// Question 3: Reentrant Logger
// Problem: cout is shared. Multiple threads writing may interleave.
// Task: Make thread-safe and reentrant.
// ==========================================================
class Logger {
public:
    void log(const std::string& msg) {
        std::lock_guard<std::recursive_mutex> lock(mtx_);
        std::cout << msg << std::endl;
        helper(); // safe because recursive_mutex allows re-lock
    }

private:
    void helper() {
        std::lock_guard<std::recursive_mutex> lock(mtx_);
        std::cout << "[helper] logging something\n";
    }

    std::recursive_mutex mtx_;
    // Pseudo-code:
    // recursive_mutex allows a function to lock mutex multiple times in same thread.
    // Prevents deadlock if log() calls helper().
};

// ==========================================================
// Question 4: Lazy Initialization Singleton
// Problem: get_instance() is not thread-safe. Multiple threads may create multiple instances.
// Task: Use std::call_once or mutex.
// ==========================================================
class Singleton {
public:
    static Singleton* get_instance() {
        std::call_once(init_flag_, []() {
            instance_ = new Singleton();
        });
        return instance_;
    }

private:
    Singleton() = default;
    static Singleton* instance_;
    static std::once_flag init_flag_;
};

// Define static members
Singleton* Singleton::instance_ = nullptr;
std::once_flag Singleton::init_flag_;

// Pseudo-code:
// std::call_once ensures the lambda is executed only once, even if multiple threads call get_instance().

// ==========================================================
// Question 5: Shared Resource with Read/Write
// Problem: Multiple threads reading/writing vector may crash.
// Task: Protect writes with mutex. Optimize reads with shared_mutex.
// ==========================================================
class SharedBuffer {
public:
    void write(int value) {
        std::unique_lock<std::shared_mutex> lock(mtx_);
        buffer_.push_back(value);
    }

    int read(size_t index) const {
        std::shared_lock<std::shared_mutex> lock(mtx_);
        return buffer_[index];
    }

private:
    std::vector<int> buffer_;
    mutable std::shared_mutex mtx_;
    // Pseudo-code:
    // shared_mutex allows multiple concurrent readers (shared_lock)
    // exclusive access (unique_lock) for writers.
};

// ==========================================================
// Example usage
// ==========================================================
int main() {
    std::cout << "=== Counter Demo ===\n";
    Counter c;
    std::thread t1([&]{ for(int i=0;i<1000;i++) c.increment(); });
    std::thread t2([&]{ for(int i=0;i<1000;i++) c.increment(); });
    t1.join(); t2.join();
    std::cout << "Counter: " << c.get() << "\n"; // Expect 2000

    std::cout << "\n=== SafeVector Demo ===\n";
    SafeVector sv;
    std::thread t3([&]{ for(int i=0;i<500;i++) sv.add(i); });
    std::thread t4([&]{ for(int i=500;i<1000;i++) sv.add(i); });
    t3.join(); t4.join();
    std::cout << "SafeVector size: " << sv.size() << "\n"; // Expect 1000

    std::cout << "\n=== Logger Demo ===\n";
    Logger logger;
    std::thread t5([&]{ logger.log("Thread 1"); });
    std::thread t6([&]{ logger.log("Thread 2"); });
    t5.join(); t6.join();

    std::cout << "\n=== Singleton Demo ===\n";
    Singleton* s1 = Singleton::get_instance();
    Singleton* s2 = Singleton::get_instance();
    std::cout << "Singleton addresses: " << s1 << ", " << s2 << "\n";

    std::cout << "\n=== SharedBuffer Demo ===\n";
    SharedBuffer buf;
    std::thread tw([&]{ for(int i=0;i<100;i++) buf.write(i); });
    std::thread tr([&]{ for(int i=0;i<100;i++) {
        if(i < buf.read(i)) continue;
    }});
    tw.join(); tr.join();

    return 0;
}

