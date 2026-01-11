
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>


struct Node{
  int value_;
  std::vector<int> neighbors;
  
  Node() : value_(0) {}
  Node(int value) : value_(value) {}
  Node(int value, std::vector<int> neighbors) : value_(value), neighbors(neighbors) {}
  
};

class Graph {
private:
    std::unordered_map<int, Node> nodes;  // Changed from vector to map
    bool directed;
    
public:
    explicit Graph(bool isDirected = false) : directed(isDirected) {}
    // Add a node
    void addNode(int value) {
        if (nodes.find(value) == nodes.end()) {
            nodes[value] = Node(value);
        }
    }
    // Add edge
    void addEdge(int from, int to) {
        addNode(from);  // Ensure both nodes exist
        addNode(to);
        nodes[from].neighbors.push_back(to);
        if (!directed) {
            nodes[to].neighbors.push_back(from);
        }
    }
    // DFS
    std::vector<int> dfs(int start) {
        std::vector<int> result;
        if (nodes.find(start) == nodes.end()) return result;  // Now this works!
        
        std::unordered_set<int> visited;  // Changed from vector<bool> to set
        dfsHelper(start, visited, result);
        return result;
    }

    std::vector<int> bfs(int start) {
      std::vector<int> result;
      if(nodes.find(start) == nodes.end()) return result;

      std::unordered_set<int> visited(nodes.size());  
      std::queue<int> qu;
      visited.insert(start);
      qu.push(start);

      while(!qu.empty()){
        int front = qu.front();
        qu.pop();
        result.push_back(front);

        for(int neigh : nodes[front].neighbors){
          if(visited.find(neigh) == visited.end()){
            qu.push(neigh);
            visited.insert(neigh);
          }

        }
      }
     return result;

    }



private:
    void dfsHelper(int node, std::unordered_set<int>& visited, std::vector<int>& result) {
        visited.insert(node);
        result.push_back(node);
        
        for (int neighbor : nodes[node].neighbors) {
            if (visited.find(neighbor) == visited.end()) { // this means if visited is false or univisited 
                dfsHelper(neighbor, visited, result);
            }
        }
    }
};

int main(){
  return 0;
}
