#include <iostream>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include <algorithm>
#include <string>

// no stack but implementing one 

// LIFO 

template<typename T>
class Stack{
  public:
    std::vector<T> stack_;
    Stack(size_t size, size_t cap) :size_(size), cap_(cap){};
    
    void push(T n){
      if ( size_ == cap_ ){
        throw std::runtime_error("error");
      }
      size_++;
      stack_.push_back(n);
      
    }

    T pop(){ // pop the last element 
      if ( size_ == 0 ) { 
        throw std::logic_error("size is 0");
      }
      T res = stack_[size_];
      stack_.pop_back();
      size_--;
      return res;
    }

  private:
  size_t size_;
  size_t cap_;

  
};


// (

class Parenthesis{
  public:
    bool isValid(std::string& input){
      std::stack<char> in; 
    
      for(auto& c : input){
        if(match.count(c)){
          if(!in.empty() && in.top() == match[c]){
            in.pop();
          }
          else{
            return false;
          }

        } else{
          in.push(c);

        }
      }
      return in.empty(); 
    }
    
  private:
  std::unordered_map<char, char> match = {
    {'}', '{'},
    {')', '('},
    {']', '['}
  }; 

};

//condition ? expr_if_true : expr_if_false

class MinStack{ 
  public:
    MinStack(){}
    
    void push(int input){
      order.push(input);
      int val = std::min(input, MinStack_.empty() ? input : MinStack_.top());
      MinStack_.push(val); 
    }
    
    int pop() {
      int res = order.top();
      order.pop();
      return res;
    }

    int getMin(){
      int res = MinStack_.top();
      MinStack_.pop();
      return res;
  }
  

private:
  std::stack<int> MinStack_;
  std::stack<int> order;

};


int main(){
  return 0;
}
