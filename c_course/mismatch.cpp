#include <algorithm>
#include <vector>
#include <string>
#include <iostream>




int main() { 
    using namespace std;
    vector<string> v1 = {"main", "foo", "bar"};
    vector<string> v2 = {"main", "fop", "baz"};

    auto diff_point = std::mismatch(v1.begin(), v1.end(), v2.begin(), v2.end());

    // diff_point is a pair of iterators
    // diff_point.first points to the first mismatch in v1
    // diff_point.second points to the first mismatch in v2

    if(diff_point.first != v1.end()) {
        cout << "First difference in v1: " << *diff_point.first << endl;
        cout << "First difference in v2: " << *diff_point.second << endl;
        
        // You can also find the position
        int position = std::distance(v1.begin(), diff_point.first);
        auto pos = find(v1.begin(), v1.end(), "foo");
        auto ir = v1.begin(); 
        cout << "Mismatch at position: " << pos - ir << endl;
        cout << "Mismatch at position: " << position << endl;
    } else {
        cout << "Vectors are identical (or one is prefix of other)" << endl;
    }
}