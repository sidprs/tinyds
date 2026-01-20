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

