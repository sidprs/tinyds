#include <sys/resource.h>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
/*

TaskScheduler scheduler;

scheduler.addTask("CompileCode", {});
scheduler.addTask("RunTests", {"CompileCode"});
scheduler.addTask("BuildDocs", {"CompileCode"});
scheduler.addTask("Deploy", {"RunTests", "BuildDocs"});

auto order = scheduler.getExecutionOrder();
// Valid output: ["CompileCode", "RunTests", "BuildDoc


*/

class TaskScheduler{

public:
  void addTask(std::string source, std::vector<std::string> destinations){
        auto it = AdjList.find(source);
        if(it == AdjList.end()){
          //this is a new entry
          AdjList.find(source) = {};
          
        } else{
          for(const auto& destination : destinations){
              AdjList[source].push_back(destination);
          }
        }
      
    }
  std::vector<std::string> dfs(std::string source){
    // recursive dfs
    std::unordered_set<std::string> visited;
    std::vector<std::string> result;

    if (AdjList.find(source)  == AdjList.end()){
      return result;
    }
    dfsHelper(source, visited, result);

    return result;


  }


  std::vector<std::string> bfs(std::string source){
    std::unordered_set<std::string> visited;
    std::vector<std::string> result;
      
    if (AdjList.find(source) == AdjList.end()){
      return result;
    }


    std::queue<std::string> qu;
    qu.push(source);
    visited.insert(source);


    while(!qu.empty()){
       std::string current = qu.front();
    
       qu.pop();
       result.push_back(current);
  

        visited.insert(source);

        for(auto &nei : AdjList[source]){
          if(visited.find(nei) != visited.end()){
            visited.insert(nei);
            qu.push(nei);
          }
        }
    }
    return result;
  }


private:
  int size_;
  int capacity_;
  std::unordered_map<std::string, std::vector<std::string>> AdjList;

  void dfsHelper(std::string source, std::unordered_set<std::string> visited, std::vector<std::string> result)
  { 
    visited.insert(source);
    result.push_back(source);

    for(auto &nei : AdjList[source]){

      if (visited.find(nei) == visited.end()) {
        dfsHelper(nei, visited, result);
      }

    }

  }

};



int main(){
  return 0;
}
