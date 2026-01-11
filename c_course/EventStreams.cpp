
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