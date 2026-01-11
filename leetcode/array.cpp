

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>


class Solutions{
  std::vector<int> TwoSum(std::vector<int>& input, int target){
    int diff = 0;
    int n = input.size();
    std::unordered_map<int, int> seen;
    for(int i{}; i < n; i++){
      diff = target - input[i];
      if(seen.find(diff) != seen.end()){
        return {seen[diff], i };
      }
      //seen[i] = input[i];
      seen.insert({input[i], i});
    }
    return {};
  }

  bool ValidAnagram(std::string & s, std::string & t){
      


  }



};



int main(){
  std::cout << "hj" << std::endl;



  return 0;
}
