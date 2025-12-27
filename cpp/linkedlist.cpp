


#include <iostream>

class LinkedList {
public:
  LinkedList();     
  LinkedList(LinkedList &&) = default;    // move assigmnet
  LinkedList(const LinkedList &) = default; // copy constructor 
  LinkedList &operator=(LinkedList &&) = default;  // move assigmnet
  LinkedList &operator=(const LinkedList &) = default; // copy assigmnet
  ~LinkedList();

private:
  
};

LinkedList::LinkedList() {
}

LinkedList::~LinkedList() {
}




int main(){

  return 0;
}
