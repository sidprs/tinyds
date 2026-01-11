#include <vector>
#include <iostream>
#include <utility>
#include <queue> 
#include <stack>
#include <unordered_set>
#include <algorithm>
/*
  
find a 1, do DFS or BFS
  pass the grid r, c  regardless
  do DFS , BFS and set the 

  
*/


class Graph{

  private:
    std::vector<std::vector<std::pair<int, int>>> adjList;
    void rec_dfs(int u, std::unordered_set<int>& vis, std::vector<int>& order ) const{
      vis.insert(u);
      order.push_back(u);
      for(const auto& [v, _] : adjList[u]){
        //(void)w; mutes the compiler 
        //if(adjList.find(v) == adjList.end()){
        if(!vis.count(v)){
          rec_dfs(v, vis, order);
        }
      }
    }

public:

    
    explicit Graph(int n ) {
      adjList = std::vector<std::vector<std::pair<int, int>>>(n);
    }
    
    int n() const { return static_cast<int>(adjList.size()); }

    void addEdge(int u, int v, int w, bool directed=false){
      
      adjList[u].push_back(std::make_pair(v, w));
      if(!directed) adjList[v].push_back({u, w}); 
  }
    
    std::vector<int> dfs( int start ){
      // recursive dfs function caller
      std::vector<int> order;
      order.reserve(n());
      std::unordered_set<int> visited;
      rec_dfs(start, visited, order);
      return order;         
    
    }  

    std::vector<int> bfs ( int start ){
      std::queue<int> qu;
      std::vector<int> order;
      std::unordered_set<int> vis;
      while(!qu.empty()){
        int curr = qu.front();
        qu.pop();
        order.push_back(curr);
        vis.insert(curr);
        for(const auto&[v,_] : adjList[curr]){
          //if(vis[v].find() == vis.end()){ 
          if(!vis.count(v)){ 
            qu.push(v);
          }
        }
      
      }
      return order;

    }

};


class Islands{
private:
  static constexpr int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
   void dfs(std::vector<std::vector<char>>& grid, int r, int c){
      // if invalid conditions 
      // return

      // go in all directions 

    }



  public:
    int numIslands(std::vector<std::vector<char>>& grid) {
      int ROWS = grid.size();
      int COLS = grid[0].size();

      for( int i{} ; i < ROWS; i++){
        for( int j{} ; j < COLS; j++){
          if (grid[i][j] == '1'){
            
          } else{
            continue;
          }
          
        }
      }

    return 1;
   }
  
 
};



int main(){
  std::cout << "hello" << std::endl;

  return 0;
}
