



//Simple Thread-Safe Solution:

#include <mutex>

class RunningTotal {
public:
    void add(int value) {
        std::lock_guard<std::mutex> lock(mtx_);
        total_ += value;
    }

    int get_total() const {
        std::lock_guard<std::mutex> lock(mtx_);
        return total_;
    }

private:
    int total_ = 0;
    mutable std::mutex mtx_;
};


//Reentrancy Consideration:

//std::mutex is not reentrant. If add() calls another function that also locks mtx_, it will deadlock.

//Use std::recursive_mutex instead:

#include <mutex>

class RunningTotal {
public:
    void add(int value) {
        std::lock_guard<std::recursive_mutex> lock(mtx_);
        total_ += value;
        helper(); // safe, can lock again
    }

    int get_total() const {
        std::lock_guard<std::recursive_mutex> lock(mtx_);
        return total_;
    }

private:
    void helper() {
        // Can safely lock again
        std::lock_guard<std::recursive_mutex> lock(mtx_);
        total_ += 1;
    }

    int total_ = 0;
    mutable std::recursive_mutex mtx_;
};
