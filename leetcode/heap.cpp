#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>



class TaskScheduler{

  public:
  
    int Scheduler(std::vector<char>& tasks, int n){
      // create counter of occurances of Task
      // put the occurances in a max heap 
      std::vector<int> frequencies(26, 0);  
      for(const auto& task : tasks){
        frequencies[task - 'A'] += 1;
      }  
      
      std::priority_queue<int> maxHeap;
      for(const auto& freq : frequencies){
        if (freq > 0) maxHeap.push(freq);
      }
      
      std::queue<std::pair<int, int>> qu;

      int time = 0;
      while(!qu.empty() || !maxHeap.empty()) {
        time++;
        // this is not neccesary but we can keep it 
        if (!maxHeap.empty()){
          int cnt = maxHeap.top()- 1;
          maxHeap.pop();
          if(cnt > 0){
           qu.push({ cnt, time + n});
          }
        }
        if(!qu.empty() && time == qu.front().second ){
          maxHeap.push({qu.front().first});
          qu.pop();
        }

      }
    return time;

  }


};





int main (int argc, char *argv[]) {
  
  return 0;
}
