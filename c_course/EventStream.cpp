
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map> 
#include <unordered_set> 
#include <stack>
#include <set>
enum class Kind{
    Begin,
    End,
};

struct Event {
     Kind Type;
     double Elapsed;       
     std::string Method;
};

using Events = std::vector<Event>;

struct Sample { 
    double Elapsed;
    std::vector<std::string> Stack; 
}; 

// Elapsed represents the amount of milliseconds
// Stack ( first is outermost function , last is the current ) - inverse FIFO 

using Samples = std::vector<Sample>;


class Result{
    public:
        void addEvent(std::vector<std::string> stack_){

        }
    private:
        Sample globalStack;
        
};



Events GenerateEvents(const Samples& samples){
/*
    Input  ;  vector<Sample> samples, 
    Output :  vector<Events> result 
*/
    Result result;
    Events fin_;
    // vector of Event structs
    for(auto &sample : samples){
        Sample s;
        s.Elapsed = sample.Elapsed;
        // add only new events to stack
        result.addEvent(sample.Stack);
    }



    return fin_;


}

int main()
{
    using namespace std;
    // Samples samples{
    // { 2.4, { "main" } },
    // { 2.5, { "main", "foo", "bar", } },
    // { 2.6, { "main", "bar", "foo",  } },
    // { 3.0, { "main", } },
    // };
    unordered_set<int> set1 = { 1, 2, 3, 4, 5,1 };
    unordered_set<int> set2 = { 3, 4, 5, 6, 7 };
    // const auto events = GenerateEvents(samples);
    vector<int> v1  {1, 2, 5, 6};
    vector<int> v2 {1, 3, 5};

    // Checking vectors are equal or not
    if (v1 == v2)
        cout << "Equal\n";
    else
        cout << "NOT Equal\n";

    auto diff_point = std::mismatch(v1.begin(), v1.end(), v2.begin(), v2.end());
    std::cout << *diff_point.first << std::endl;
    std::cout << *diff_point.second << std::endl;
    auto diff_distance = std::distance(v1.begin(), diff_point.first);
    auto b =  v1.begin();
    std::cout << *b << std::endl;
    std::cout << "diff_distance : " << diff_distance << std::endl;
    // unordered_set<int> difference;

    // Use set_difference to find difference
    // set_difference(
    //     set1.begin(), set1.end(), set2.begin(), set2.end(),
    //     inserter(difference, difference.begin()));

    // Print the difference
    // cout << "Set after Difference: ";
    // for (auto const& elem : difference) {
    //     cout << elem << " ";
    // }
    // cout << endl;


    return 0;
}