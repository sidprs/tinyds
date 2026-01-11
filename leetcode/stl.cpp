#include <iostream>
#include <vector>
#include <algorithm>




int main(){
  
  std::unordered_map<int, int> unord_map;
  std::vector<int> m =  {1, 9, 3, 2};
  
  auto it = std::find(m.begin(), m.end(), 9);
  std::cout << "at position " << *it << std::endl;
  


  std::cout << "hi" << std::endl;
  return 0;
}
