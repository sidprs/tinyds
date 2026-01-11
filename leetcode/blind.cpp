#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>

class ArrayHash{

  public:
    bool containsDuplicate(std::vector<int>& input);
    bool duplicate(std::vector<int>&inp);
    bool validAnagram(std::string& s, std::string& t);

  private:


};

struct node{
  int index_;  
  Node() : index_(0) {}
  Node(int index) : index_(index) {}
  Node(int index, vector<node*> _nei) : index_(index), nei_(_nei) {}
  std::vector<int> nei_;
};


class Graph{
  public:
    std::vector<node> CloneGraph(std::vector<std::vector<int>>&adjList);
  private:
    std::vector<node> copy;

};


std::vector<node> Graph::CloneGraph(std::vector<std::vector<int>>&adjList){
  copy.reserve(adjList.size());

  for(int i{}; i < adjList.size(); i++){
    node* newnode = new node;
    newnode.index_ = i;
    newnode.nei_ = (adjList[i]);
    copy.push_back(newnode);
  }

  // copy is a vector of nodes

} 


bool ArrayHash::containsDuplicate(std::vector<int>& input) {
    std::unordered_set<int> seen;
    
    for (const auto& num : input) {
        // Method 1: Using find()
        if (seen.find(num) != seen.end()) {
          return true;  // Found duplicate!
        }
        seen.insert(num);
         
        // Method 2: Using count() - simpler!
        // if (seen.count(num)) {
        //     return true;
        // }
        // seen.insert(num);
    }
    
    return false;  // No duplicates found
}

bool ArrayHash::duplicate(std::vector<int>&nums){
  return std::unordered_set<int>(nums.begin(), nums.end()).size() < nums.size();
  // makes a set from the vector inp then checks the sizes to see if its lesser
  // if the set size is smaller then return true that it contains a duplicate
  // unordered_set <int> (num.begin(), nums.end())
}

bool ArrayHash::validAnagram(std::string& s, std::string& t){
  // set for s, t
  // make sure they are identical
  if(s.size() != t.size()) return false;
  int cnt[256] = {0};
  for(unsigned char c: s) cnt[c]++;
  for(unsigned char c: t) {
    if(--cnt[c] < 0) return false;
  }
  return true;
}

int main(){

  return 0;
}
