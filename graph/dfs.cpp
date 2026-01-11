

#include <iostream>
#include <unordered_map>
#include <unordered_set>



template<typename W, typename V>
struct Node{
  W weight_;
  V value_;
  bool occupied_;
  
  Node(W weight_, V value_) : weight_(weight_), 
                              value_(value_)
  {
  }
};


template<typename W, typename V>
class Graph{
  private:
  std::unordered_map<Node<W,V>, std::vector<Node<W,V>>> adjList;
  std::unordered_set<Node<W,V>> visited;
  
  public:
  void createAdjList(std::vector<Node<W,V>> node )


};
