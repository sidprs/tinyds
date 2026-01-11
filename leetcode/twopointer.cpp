#include <iostream>
#include <vector>


class TwoPointer{
  private:
    

  public:
    int WaterCalculation(const std::vector<int>& heights){
      int left_position = heights.size()-1;
      int right_position = 0;
      int maxArea = 0;
      int area = 0;
      int diff = 0;

      while(right_position > left_position) {
        diff = right_position - left_position;
        area = diff  * std::min(heights[right_position], heights[left_position]);
        maxArea = std::max(maxArea, area);
        if(heights[left_position] <= heights[right_position]){
          left_position++;
        }else{
          right_position--;
        }
      }
      
      // area = abs(h[l] - h[r]) * (r - l + 1)
      
    return maxArea;
    }


};


int main(){
  return 0;
}
