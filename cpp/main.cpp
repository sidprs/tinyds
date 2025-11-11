#include <iostream>
#include <vector>
  
#include <mutex>
#include <condition_variable>
#include <stdexcept>


class RingBuffer{

  private:
   int head_; 
   int tail_; 
   int capacity_;
   int size_;
   int* array_;

  public:
    RingBuffer(int capacity_) : size_(0), head_(0), tail_(0){
      array_ = new int [capacity_];

    }
    ~RingBuffer();
    RingBuffer(const RingBuffer&) = default;
    RingBuffer(RingBuffer&&);
      
    RingBuffer operator=(const RingBuffer&);
    RingBuffer operator=( RingBuffer&&);


};



int main(){

  

  return 0;

}
