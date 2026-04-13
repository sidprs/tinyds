#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
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

// free form interview 
// time_stamp | value | quality | 

// quality  < min_quality (drop)
// if many t_ms exists keep the higher quality


struct Sample { long long t_ms; double value; int quality; };

class Verifier {
public:
    explicit Verifier(size_t window_size, int min_quality) : window_size(window_size), min_quality(min_quality)    , ingest_counter(0) 
    {
       

    }
    // Adds a raw sample.
    void ingest(const Sample& s){
      if (s.quality < min_quality) return;
      auto it = sampleMap_.find(s.t_ms);
      if(it == sampleMap_.end())
      {
        sampleMap_.emplace(s.t_ms, Entry{s, ingest_counter++}); 
      } else{
        if(s.quality > it->second.sample.quality){
          it->second = Entry{s, ingest_counter++};
        }
      }
      while(sampleMap_.size() > window_size){
        auto oldest  = sampleMap_.begin();
        const Sample final = oldest->second.sample;
        finalized_.push_back(final);
        sampleMap_.erase(oldest);
      }
    }
  
    // Returns all “verified” outputs that are now finalized, in time order.
    // A verified output is produced for timestamps that are "stable" based on a sliding window.
    std::vector<Sample> flush_verified(){
      // clear finalized values and return the values before
      std::vector<Sample> out;
      out.swap(finalized_); 
      return out;
        //return std::exchange(finalized_, {}); 
    }

  private:
    std::vector<Sample> finalized_;
    size_t window_size;  
    int ingest_counter;  
    int min_quality;

    struct Entry {
      Sample sample;
      long long time_stamp;
    };
    std::map<long long, Entry> sampleMap_;
};





/*
 
return the t_ms (t) when this happens 
altitude_m < 150

altitude_m > 3000

abs(v_mps) > 8



*/


class BalloonFleet1{

 private:
   struct Telemetry{
    int id;
    long long t_ms;
    double altitude;
    double v_mps;
    };

    size_t capacity_;
    int size_;
    std::map<int, Telemetry> entries_;
    std::vector<Telemetry> invalid;
 public:
    
  BalloonFleet1(size_t capacity_) : size_(0), capacity_(capacity_) {}

  void addEntry(const Telemetry& input){
    auto it = entries_.find(input.id);
    if(it != entries_.end()){
      // we have seen this one before 
      const Telemetry& last_input = it->second;
      if(input.t_ms > last_input.t_ms){

      }
    }
    else{
      if(input.altitude < 150 || input.altitude > 3000 || abs(input.v_mps) > 8){
        invalid.push_back(input);
      }
      else{
        entries_[input.id] = input;
      }


    }
  }

  void printInvalid(void){
    for(const auto& [key, value] : entries_){
      std::cout << "key " << key << " value : " << value.id << std::endl; 
    }
  }

  
};





#include <cmath>
#include <iostream>
#include <iomanip>
#include <map>
#include <limits>

class BalloonFleet {
public:
    struct Telemetry {
        int id;
        long long t_ms;     // milliseconds
        double altitude_m;  // meters
        double v_mps;       // m/s (piecewise constant between telemetry points)
    };

    BalloonFleet() = default;

    // Part A: ingest telemetry and record first unsafe time per balloon
    void addEntry(const Telemetry& cur) {
        // If we already found first violation for this balloon, we can ignore later updates.
        if (first_bad_time_.count(cur.id)) {
            return;
        }

        // 1) Instantaneous checks at the telemetry timestamp
        if (isInstantUnsafe(cur)) {
            first_bad_time_[cur.id] = static_cast<double>(cur.t_ms);
            return;
        }

        // 2) Interval checks between last telemetry point and this one (altitude crosses thresholds)
        auto it = last_.find(cur.id);
        if (it != last_.end()) {
            const Telemetry& prev = it->second;

            // If timestamps are equal or out-of-order for same id, treat as instantaneous-only update.
            if (cur.t_ms > prev.t_ms) {
                double t_cross = firstAltitudeCrossingTimeMs(prev, cur.t_ms);
                if (t_cross < std::numeric_limits<double>::infinity()) {
                    first_bad_time_[cur.id] = t_cross;
                    return;
                }
            }

            // Also check instantaneous altitude at cur.t_ms already done above.
        }

        // Update last known telemetry for this balloon
        last_[cur.id] = cur;
    }

    // Print the results for Part A: id -> first unsafe time, sorted by id
    void printFirstViolations(std::ostream& os = std::cout) const {
        // Print ms; keep decimals if crossings produce fractional ms
        os << std::fixed << std::setprecision(3);
        for (const auto& [id, t] : first_bad_time_) {
            os << id << " " << t << "\n";
        }
    }

    // If you want the map programmatically
    const std::map<int, double>& firstBadTimes() const { return first_bad_time_; }

private:
    // Safety thresholds
    static constexpr double kMinAlt = 150.0;
    static constexpr double kMaxAlt = 3000.0;
    static constexpr double kMaxAbsV = 8.0;

    static bool isInstantUnsafe(const Telemetry& s) {
        return (s.altitude_m < kMinAlt) ||
               (s.altitude_m > kMaxAlt) ||
               (std::abs(s.v_mps) > kMaxAbsV);
    }

    // Returns earliest crossing time (ms) in (prev.t_ms, t1_ms] based on piecewise-constant v_mps from prev.
    // Uses the model altitude(t) = prev.altitude_m + prev.v_mps * (t - prev.t_ms)/1000.
    // If no crossing, returns +infinity.
    static double firstAltitudeCrossingTimeMs(const Telemetry& prev, long long t1_ms) {
        const long long t0 = prev.t_ms;
        const double v = prev.v_mps;
        const double dt_ms = static_cast<double>(t1_ms - t0);

        // Predict altitude just before t1 using prev's constant velocity model
        const double alt0 = prev.altitude_m;
        const double alt1_pred = alt0 + v * (dt_ms / 1000.0);

        double best = std::numeric_limits<double>::infinity();

        // If v == 0, altitude is constant over the interval -> no crossing (if unsafe at t0, would be caught earlier)
        if (v == 0.0) return best;

        auto considerThreshold = [&](double H) {
            // Solve alt0 + v*(dt/1000) = H => dt_ms = (H - alt0)/v * 1000
            const double cand_dt_ms = (H - alt0) / v * 1000.0;
            if (cand_dt_ms > 0.0 && cand_dt_ms <= dt_ms) {
                // Ensure it actually crosses within the segment directionally (helps with floating noise)
                // Crossing occurs if alt0 and alt1_pred are on different sides or exactly at threshold at end.
                const bool crosses =
                    (alt0 - H) * (alt1_pred - H) <= 0.0; // sign change or touches
                if (crosses) {
                    const double cand_t = static_cast<double>(t0) + cand_dt_ms;
                    if (cand_t < best) best = cand_t;
                }
            }
        };

        // Crossing below min or above max can be detected by checking the boundary thresholds.
        considerThreshold(kMinAlt);
        considerThreshold(kMaxAlt);

        return best;
    }

private:
    std::map<int, Telemetry> last_;        // last telemetry per balloon id
    std::map<int, double> first_bad_time_; // first unsafe time per balloon id (ms; may be fractional)
};

/* Example usage:
int main() {
    BalloonFleet fleet;
    fleet.addEntry({1, 0,    500,  3});
    fleet.addEntry({1, 1000, 3500, 3});  // instant unsafe at t=1000
    fleet.addEntry({2, 0,    200, -1});
    fleet.addEntry({2, 2000, 100, -1});  // crosses 150 between, computed from prev segment

    fleet.printFirstViolations();
}
*/

