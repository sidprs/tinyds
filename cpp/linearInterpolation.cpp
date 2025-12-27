#include <iostream>
#include <unordered_map>


// y = y₁ + (x - x₁) * (y₂ - y₁) / (x₂ - x₁)
class VelocityBarConversion{
  private:
    double currVelocity_;
    std::unordered_map<double, double> chart_;
     
  public:
    void EnterEntry(double bar){
      chart_[currVelocity_] = bar;
    } 
    double LinearInterpolation(std::pair<double, double> x1, std::pair<double, double> x2){
      
    } 



};


int main(){


  return 0;
}
