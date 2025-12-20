/*
* LOG PROBLEM
* Author : Sid Prasad
* Question 1
*/


/*
  <timestamp_ms> <user_id> <session_id> <event> [kv_pairs...]

  input file 

  n : entries
-------------------------------------------------
|  8
|  100 u1 s1 START
|  110 u1 s1 PAGE url=/home
|  120 u1 s1 CLICK id=btnA
|  150 u1 s1 PURCHASE amount=4999 item=X
|  160 u1 s1 END
|  90 u1 s2 PAGE url=/oops
|  200 u1 s2 START
|  250 u1 s2 END
|
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <cctype> 
#include <string>
#include <sstream>

namespace SESH {
  enum class Event{
    START, PAGE, CLICK, PURCHASE, END
  };

  enum class State{
    IN, INVALID, OUT
  };
  enum class Code {
    READ_0, WRITE_0,
    READ_1, WRITE_1,
    LOG_0, LOG_1 
  };
};

template <typename K, typename V>
struct Event{
  K key_; 
  V value_;
};

struct Meta{
  double timestamp_ms;
  int user_id;
  int session_id;
};


template <typename K, typename V>
class Log{
  public:
    explicit Log(const std::string& fname) : Filename(fname){}
  SESH::Code LogFileParser(){
      using code = SESH::Code;
      std::cout << "[ LogFileParser ]" << std::endl;
      std::ifstream file(Filename); // create instance of file
      if(!file.is_open()) { std::cerr << " Error opening file " << Filename << "\n"; return code::READ_1;}
      clearData();
      std::string line;
      int line_number = 0;
      std::string segment;
      std::vector<int> segments;

      while (std::getline(file, line)) {
        line_number++;
        auto l = line.find('<');
        // find('char_searching', start_pos)
        if( l == std::string::npos) return code::READ_1;
        auto r = line.find('>', l+1);
        if (r == std::string::npos) return code::READ_1;
        std::string inside = line.substr(l + 1, r - l - 1);
        std::stringstream ss_int(inside);
        int x;
        while (ss_int >> x) segments.push_back(x);
        LogInts_[line_number] = segments;
      }
      //clearData();
    return code::READ_0;
  }            

  void Print() {
        for(const auto& [line_num, values] : LogInts_) {
            std::cout << "< ";
            for(const auto& val : values) {
                std::cout << val << " ";
            }
            std::cout << "> (line " << line_num << ")\n";
        }

  }
  private:
    std::string Filename;
    std::vector<std::string> LogData_;
    std::unordered_map<int, std::vector<int>> LogInts_;
    std::vector<Meta> MetaData_;
    void clearData(){
      LogInts_.clear();
    }

};




int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: ./log <file>\n";
    return 1;
  }

  std::string filename = argv[1];

  std::cout << filename << std::endl;
  Log<std::string, std::string> logger(filename);
  logger.LogFileParser();
  logger.Print();

  //

  return 0;
}
