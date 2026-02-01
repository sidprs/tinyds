#include <iostream>
#include <list>

class LRU{
  int get(int key){
    auto it = mp_.find(key);
    if(it == mp_.end()){
      return  -1;    
    }
    return it->second.value; 

  }
  
  void put(int key, int value){
    auto it = mp_.find(key);
    if(it != mp_.end()){
      it->second.value = value;
      touch(key);
      return;
    }
    if((int)mp_.size() == cap_){
      int lru = order_.back();
      order_.pop_back();
      mp_.erase(lru);
    }
    order_.push_front(key);
    auto[_, inserted] = mp_.emplace(key, Node{value, order_.begin()});
    (void)inserted;
  }
  
  private:
    size_t cap_;
    struct Node {
      int value;
      std::list<int>::iterator list_it;
    };
    std::list<int> order_; // stores the keys of the MRU (front) LRU (end)
    std::unordered_map<int, Node> mp_;

    void touch(int key){
      auto it = mp_.find(key);
      if(it == mp_.end()) return;
      order_.splice(order_.begin(), order_, it->second.list_it); 
      it->second.list_it = order_.begin();
    
    }
};



int main(int argc, char* argv[]){



  return 0;
}
