

#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

class ArrayHash {
 public:
  int LongestConsecSeq(std::vector<int>& input);
  bool ValidSudoku(std::vector<std::vector<char>>& board);
  std::vector<std::vector<std::string>> GroupAnagram(
      std::vector<std::string>& input);
  std::vector<int> TopKElements(std::vector<int>& nums, int k);
};

class EncoderDecoder {
 public:
  std::string Encode(std::vector<std::string>& input);
  std::vector<std::string> Decode(std::string& input);

 private:
  std::string encodedString;
};
