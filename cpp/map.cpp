



#include <iostream>
#include <map>
/*
template<
    class Key,
    class T,
    class Compare = std::less<Key>,
    class Allocator = std::allocator<std::pair<const Key, T>>
> class map;


*/


template<typename T, typename K>
struct Slot{
  T index_;
  K value_;
  bool occupied_ = false;

};


template<typename T, typename K>



int main(){
  std::cout << "Hello World" << std::endl;

return  0;
}
