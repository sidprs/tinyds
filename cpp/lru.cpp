#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stdexcept>

template<typename T=int>
class LRU{
  private:
    struct Task{
      long long t_ms;
      int taskid;
      T pid
    };
  
  size_t capacity_;
  int size_;
  Task* LRU;
  Task* MRU;
  Task* head_;
  Task* tail_;

  std::unordered_map<int, Task> Cache_;
  
  public:
    LRU(size_t capacity) : capacity_(capacity), size_(0)
        LRU{nullptr}, MRU{nullptr}, head_{nullptr}, tail_{nullptr} { }
    
    void addToFront(){}
    void remove(){}

    
};


class LRUCache{
  public:
    explicit LRUCache(size_t capacity) : capacity_(capacity){
      
    }
    void put(int key, int value){


    }

    int get(int key){


    }

  private:
    std::list<int> order_;
    struct Node{
      int key_;
      std::list<int>::iterator l_it;
    };

    std::unordered_map<int, Node> mp_;

    void touch(std::unordered_map<int, Node>::iterator::it){
      // “Take the node at it->second.l_it from order_ and move it so it becomes the first element (order_.begin()) in order_.”
      //order_.splice()
      // l1.splice(pos, l2, first, last);     // For range of elements.
      order_.splice(order_.begin(), order_, it->second.l_it);
      order_.erase(l_it);
      order_.push_front(key);

    }


};




class LRUCache {
public:
  explicit LRUCache(int capacity) : cap_(capacity) {}

  int get(int key) {
    auto it = mp_.find(key);
    if (it == mp_.end()) return -1;
    touch(it);
    return it->second.value;
  }

  void put(int key, int value) {
    if (cap_ == 0) return;

    auto it = mp_.find(key);
    if (it != mp_.end()) {
      it->second.value = value;
      touch(it);
      return;
    }

    if ((int)mp_.size() == cap_) {
      int lru = order_.back();
      order_.pop_back();
      mp_.erase(lru);
    }

    order_.push_front(key);
    mp_.emplace(key, Node{value, order_.begin()});
  }

private:
  struct Node {
    int value;
    std::list<int>::iterator l_it;
  };

  int cap_;
  std::list<int> order_;                 // front=MRU, back=LRU
  std::unordered_map<int, Node> mp_;     // key -> {value, iterator}

  void touch(std::unordered_map<int, Node>::iterator it) {
    order_.splice(order_.begin(), order_, it->second.l_it); // move node to front
    it->second.l_it = order_.begin();
  }
};

