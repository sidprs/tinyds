#include <iostream>
#include <vector>
// t interview

template<typename T>
struct node{
  T value;
  int index = 0;
};

template<typename T>
class RingBuffer {
 public:
  explicit RingBuffer(int cap)
      : 
        capacity_(cap),
        list_(nullptr),
        size_(0),
        head_(0),
        tail_(0) 
    {
        if (cap == 0){
            throw std::invalid_argument("RingBuffer capacity must be > 0");
        }  
      list_ = new node<T>[capacity_];
    }

  // FIFO 
  // 1, 2, 3, 4
  // 5, 2, 3

  void push(T value){
    node<T> n{value, size_};

    if(this->size_ == this->capacity_){
      std::cout << "overwrite" << std::endl;
      this->head_ = (this->head_ + 1) % this->capacity_;
    }
    std::cout <<"push " << value << std::endl;
    this->size_++;
    list_[this->tail_] = n;    
    this->tail_ = (this->tail_ + 1) % this->capacity_;
    
  }
  node<T> pop(){
        node<T> n = list_[head_];
    if(!this->list_){
      std::cout << "error empty" << std::endl;
    }
    n.value = this->list_[this->head_].value;
    this->size_--;
    this->head_ = (this->head_ + 1) % this->capacity_;
    return n;
  }
 private:
  node<T> *list_;
  int capacity_;
  int size_;
  int head_;
  int tail_;
};

int main(int argc, char *argv[]) { 
  RingBuffer<int> r(4);

    r.push(1);
    r.push(2);
    r.push(3);
    r.push(4);
    r.push(5);           // overwrites 1










  return 0;
}
