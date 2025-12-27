#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>
#include <string> 



using IntPair = std::pair<int, int>;

class LERP{
  public:
    void ReadData(std::ifstream& inputFile){
      
    if (inputFile.is_open()) {
      std::cout << "File opened successfully. Reading data..." << std::endl;
    }

    IntPair pair;
    while(inputFile >> pair.first >> pair.second){
        entries_.push_back(pair);
        entrySize_++;
      } 

    inputFile.close();
    
    for(const auto& e : entries_){
      std::cout << "[first: " << e.first << " second : " << e.second << " ]"<< std::endl; 
    }

  }
    

  private:
    std::vector<IntPair> entries_;
    size_t entrySize_;
     



};


int main(){
   LERP lerp;
   std::ifstream file("data.txt");
   lerp.ReadData(file);

  std::cout << "hello world" << std::endl;
  return 0;  

}



