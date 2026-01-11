#include <iostream>
#include <stdexcept>
#include <iterator>

template<typename T>
struct node {
  T value;
  int index = 0;
};

template<typename T>
class RingBuffer {
 public:
  explicit RingBuffer(size_t cap)
      : capacity_(static_cast<int>(cap)),
        size_{0},
        head_{0},
        tail_{0} {
    if (cap == 0) {
      throw std::invalid_argument("RingBuffer capacity must be > 0");
    }
    list_ = new node<T>[capacity_];
  }

  ~RingBuffer() { delete[] list_; }

  void push(const T& value) {
    node<T> n{value, size_};
    // value = value
    // index = size

    if (size_ == capacity_) {
      head_ = (head_ + 1) % capacity_;
    } else {
      ++size_;
    }
    list_[tail_] = n;
    tail_ = (tail_ + 1) % capacity_;
  }

  node<T> pop() {
    if (size_ == 0) throw std::logic_error("pop from empty RingBuffer");
    node<T> n = list_[head_];
    head_ = (head_ + 1) % capacity_;
    --size_;
    return n;
  }

  bool isEmpty(){
    return (size_ == 0);
  }

  // iterator
  class iterator {
   public:
    using iterator_category = std::forward_iterator_tag;
    using value_type        = node<T>;
    using difference_type   = std::ptrdiff_t;
    using pointer           = node<T>*;
    using reference         = node<T>&;

    iterator(node<T>* data, int cap, int pos, int count)
        : data_(data), cap_(cap), pos_(pos), remaining_(count) {}

    node<T>& operator*() { return data_[pos_]; }
    node<T>* operator->() { return &data_[pos_]; }

    iterator& operator++() {
      pos_ = (pos_ + 1) % cap_;
      --remaining_;
      return *this;
    }

    bool operator!=(const iterator& other) const {
      return remaining_ != other.remaining_;
    }

   private:
    node<T>* data_;
    int cap_;
    int pos_;
    int remaining_;
  };

  iterator begin() { return iterator(list_, capacity_, head_, size_); }
  iterator end()   { return iterator(list_, capacity_, 0, 0); }

 private:
  node<T>* list_;
  int capacity_;
  int size_;
  int head_;
  int tail_;
};

int main() {
  RingBuffer<int> r(4);
  r.push(1);
  r.push(2);
  r.push(3);
  r.push(4);
  r.push(5);

  for (auto& v : r) {
    std::cout << v.value << '\n';
  }
}

