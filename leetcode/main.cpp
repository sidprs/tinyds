#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <optional>


/*
leetcode in c++17 
author : sid
*/




template<typename T>
struct Node{
  T value_;
  int index_;
  Node(T value): value_(std::move(value>), index_(0){}
};


template<typename T, typename W = int >
class Graph{
  private:
    size_t listSize_;
    size_t listCapacity_;
    using node = Node<T>;
    node* List_;
    std::unordered_map<node, std::vector<std::pair<node, node>>> adjList;  // pair<neighbor, weight>
  public:
    
    explicit Graph(size_t listCapacity) : listCapacity_(listCapacity), listSize_(0){
      List_ = new node[listCapacity_];
    }
  
    std::vector<node>> dfs(){
      std::vector<node> order;
      if (adjList.size() == 0){
        throw std::invalid_argument(" Cannot DFS on a empty list");
      } 
      

      return order;
  
    }
      


};





int main (int argc, char *argv[]) {
  std::cout << "Hello world " << std::endl;
  std::cout << "je"
  for(int n{}; n < 3 ;++n){
    Node n(3)

  }
  Graph<int> input(3){1,2,3};


  return 0;
}
