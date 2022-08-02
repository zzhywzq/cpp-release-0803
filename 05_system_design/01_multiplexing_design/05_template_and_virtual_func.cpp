#include <iostream>
using namespace std;

template <typename T>
class MyClass {
public:
    template <typename R>
    virtual void func() {} 
    // virtual func maybe replaced at program run
    // so template func cannot be specified at compile
};

int main() {
    return 0;
}