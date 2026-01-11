#include <sys/_types/_key_t.h>
#include <iostream>
#include <iterator>



template<typename K, typename V>
struct Node{
    K key_;
    V value_;
    bool occupied_; 
    Node(): key_(0), value_(0), occupied_(true)
    {}
    Node(K key_, V val_): key_(key_), value_(val_), occupied_(true)
    {}
};


template<typename K, typename V>
class DoublyLinkedList{

  private:
    int head_;
    int tail_;
    std::vector<Node<K,V>> LL_;
    int capacity_;
    int  size_;
    
  // implement push to the front
   


  // implement remove node 
  

  // implement add to the front 
    

  public:
    DoublyLinkedList(int capacity) : head_(0), tail_(0), capacity_(capacity), size_(0) {
        for(int i = 0; i < capacity_; i++){
          LL_[i]->occupied_ = false;
        }

    }
    ~DoublyLinkedList() = default;
    DoublyLinkedList(const DoublyLinkedList&) = default;
    DoublyLinkedList(DoublyLinkedList&&) = default;

    DoublyLinkedList& operator=(const DoublyLinkedList&) = default;
    DoublyLinkedList& operator=(DoublyLinkedList&&) = default;
    
    void Push(K key, V val){
    



    }

    std::pair<K,V> Pop(){

    }
 

    
};


int main(){



  return 0;
}
