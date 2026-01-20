#include <iostream>
#include <cmath>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

class NumIslands{
  public:
    int NumIslandsCalcBFS(std::vector<std::vector<char>>& grid_){
      int ROWS = grid_.size();
      int COLS = grid_[0].size();
      int islands = 0;

      for(int i{}; i < ROWS; i++){
        for(int j{}; j < COLS; j++){
          if(grid_[i][j] == '1'){
            bfs(i, j, grid_);
            islands++;
          }
        }
      } 

      return islands;     
    }
  private:
    const static directions = {[1,0], [0,1], [-1, 0], [0,-1]};
    void bfs(int row, int col, std::vector<std::vector<char>& grid_){
      std::queue<std::pair<int, int>> qu;
      qu.push({row, col});

      while(!qu.empty()){
        std::pair<int,int> curr = qu.front();
        qu.pop();
        for(auto d : directions){
        } 
        

      }

    }  

};


class DronePoints{
  public:
    using coords = std::pair<int,int>; 
    int visiblePoints(std::vector<coords>& coords_list, int angle, coords& location){
      // d - degrees
      // field of view = [d - (angle / 2), d + angle / 2]
      // abs(theta - d) <= angle / 2 
      
      // connvert every point relative to location into angle 
      // sort them and then use a sliding window on a circular array
      const double PI = acos(-1.0);
      std::vector<double> convertedAngles;
      int locx = location.first;
      int locy = location.second;
      int same;
      for(const auto& p : coords_list){
        int dx = p.first  - locx;
        int dy = p.second - locy;
        if (dx == 0 && dy == 0) {
          same++; // always visible
        } else {
          double a = atan2((double)dy, (double)dx); // [-pi, pi]
          double b = (a * 180) / PI; 
          convertedAngles.push_back(b);
        }    
      }
      if (convertedAngles.empty()) return same;
      
      std::sort(convertedAngles.begin(), convertedAngles.end());
      for(auto &p: convertedAngles){
        convertedAngles.push_back(p+360);
      }
      int start = 0;
      int count = 0;
      
      for(int i{}; i< convertedAngles.size(); i++){
        if(convertedAngles[i] - convertedAngles[start] > angle){
          start++;
        }
        count = std::max(count, i - start + 1);
        
      }
      return count;
    }


};

int main(int argc, char* argv[]){


  return 0;
}
