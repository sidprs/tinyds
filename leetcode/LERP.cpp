#include <iostream>
#include <vector>
#include <map>
#include <stdexcept>


class LERP{
  private:
    std::map<double, double> data_;
  public:
    void addEntry(double bar, double pressure){
      data_[bar] = pressure;
    } 
    
    
    double interpolate(double bar) const {
        if (data.empty()) {
            throw std::runtime_error("No data points available");
        }
        
        // Find the first element >= bar (upper bound)
        auto upper = data.lower_bound(bar);
        
        // Case 1: Exact match found
        if (upper != data.end() && upper->first == bar) {
            return upper->second;
        }
        
        // Case 2: bar is beyond all data (extrapolation not allowed)
        if (upper == data.end()) {
            throw std::runtime_error("Bar value too high - outside data range");
        }
        
        // Case 3: bar is before all data (extrapolation not allowed)
        if (upper == data.begin()) {
            throw std::runtime_error("Bar value too low - outside data range");
        }
        
        // Case 4: Need to interpolate between two points
        auto lower = upper;
        --lower;  // Move to the point just before upper
        
        double bar1 = lower->first;
        double pressure1 = lower->second;
        double bar2 = upper->first;
        double pressure2 = upper->second;
        
        // Linear interpolation formula: y = y1 + (x - x1) * (y2 - y1) / (x2 - x1)
        double interpolated = pressure1 + (bar - bar1) * (pressure2 - pressure1) / (bar2 - bar1);
        
        std::cout << "Interpolating between:\n";
        std::cout << "  Lower: (" << bar1 << " bar, " << pressure1 << " pressure)\n";
        std::cout << "  Upper: (" << bar2 << " bar, " << pressure2 << " pressure)\n";
        std::cout << "  Result at " << bar << " bar: " << interpolated << " pressure\n";
        
        return interpolated;
    }
    double LinearSearch(double bar) const{

        double lower_bar = -1, lower_pressure = -1;
        double upper_bar = -1, upper_pressure = -1;
        bool found_lower = false, found_upper = false;
        


      for(const auto&[b, p] : data_){
        if (b == bar) return p;
         

      }


      }



};


class Solution { 
public:






}
