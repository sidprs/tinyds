#include <iostream>
#include <vector>
#include <unordered_map>

/*

objected oriented programming 
composition : has a  
inheritance : reuse behaviour is a  
abstraction : 


*/

using namespace  std;

class Shape{
    public:
    virtual void calc(){
        cout << " Area is" << endl;
    }

    ~Shape(){
        cout << " shape destructor is" << endl;
    }

};

class Rectangle : public Shape{
    public:
    void calc() override{
        cout << " Area of rectangle is" << endl;
    }
 
    ~Rectangle(){
        cout << " Rectangle destructor" << endl;
    }
 
};

    
int main(){
    Shape *S;

    Rectangle r;
    S = &r;
    S->calc();

    cout << "hello" <<  endl;

return 0;
}

