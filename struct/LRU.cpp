#include <iostream>
#include <vector>
#include <unordered_map>

/*
  LRU Cache 
  doubly linked list 
  LRU ( left pointer )
  MRU ( right pointer)
  
  task1, task2 , task3

*/

template<typename K, typename V>
class LRUCache{
  private:
    struct Task{
      K key;
      V value;
      Task* prev = nullptr;
      Task* next = nullptr;

      Task(K k, V v): key(k), value(v) {}
    };
    std::unordered_map<K, Task*> cache_;
    Task* ListTasks_;
    size_t capacity_ ; size_t size_;
    Task* LRU_ ; Task* MRU_;
    

    void addToFront(Task* T){
      T->next = MRU_->next;
      T->prev = MRU_;
      MRU_->next->prev = T;
      MRU_->next = T;
    }

    void removeTask(Task* T){
      T->prev->next = T->next;
      T->next->prev = T->prev;
    }

    void moveToFront(Task* T){
      removeTask(T);
      addToFront(T);
    }

    void removeTail(){
      Task* tail = LRU_->prev;
      removeTask(tail); 
      cache_.erase(tail->key);
      delete tail;
    }
      
    void printCache(){
      for(const auto&[key, Task] : cache_){
        std::cout << "key is" << key << std::endl;
        std::cout << "value is" << Task->value << std::endl;
      }
      std::cout << " done with cache";
      
      Task* curr = MRU_->next;
      while(curr != LRU_){
           std::cout << "key: " << curr->key 
              << ", value: " << curr->value << std::endl;
        curr = curr->next;
      }

    }

  public:
    LRUCache(size_t capacity): capacity_(capacity), size_{0}{
      ListTasks_ = new Task[capacity_];
    }

    ~LRUCache(){
      delete[] ListTasks_;
    }
    
    LRUCache(const LRUCache&) = delete;
    LRUCache(LRUCache&&) = default;
    LRUCache& operator=(const LRUCache&) = delete;
    LRUCache& operator=(LRUCache&&) = default;

    void put(const K& key, const V& value){
      // key exists in the cache
      if(cache_.find(key) != cache_.end()){
        Task* t = cache_[key];
        t->value = value;
        moveToFront(t);
        return;
      }
      
      if(size_ == capacity_){ throw std::runtime_error("size == capacity cannot push");}

      Task* newTask = new Task(key, value);
      cache_[key] = newTask;
      addToFront(newTask);
      size_++;
 
  }

    V get(const K& key){
      if(cache_.find(key) == cache_.end()){
        throw std::runtime_error("does not exist");
      }
      return cache_[key]->value;

    }

     
};

int main(int argc, char* argv[]){


  return 0;
}
