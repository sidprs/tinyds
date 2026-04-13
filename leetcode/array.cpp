

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cmath>

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
 
};

class Solution {
public:

    int characterReplacement(std::string s, int k) {
        std::unordered_map<char, int> count;
        int res = 0;

        int l = 0, maxf = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxf = std::max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = std::max(res, r - l + 1);
        }

        return res;
    }
};


int main(){
  std::cout << "hj" << std::endl;



  return 0;
}
