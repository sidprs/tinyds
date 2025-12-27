#include <iostream>
#include <vector>
#include <unordered_map>
/*
leetcode in c++17 
author : sid
*/




template<typename T>
struct Node{
  T value_;
  int index_;
  Node(): value_(value_), index_(0){}
};


template<typename T>
class Graph{
  private:
    size_t listSize_;
    size_t listCapacity_;
    using node = Node<T>;
    node* List_;
    std::unordered_map<node, std::vector<node>> weighted_adjList;  
    std::unordered_map<node, std::vector<std::pair<node, node>>> unweighted_adjList;  // pair<neighbor, weight>
  public:
    explicit Graph(size_t listCapacity) : listCapacity_(listCapacity), listSize_(0){
      List_ = new node[listCapacity_];

    }
      


};





int main (int argc, char *argv[]) {
  std::cout << "Hello world " << std::endl;


  return 0;
}
