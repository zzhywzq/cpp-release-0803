#include <iostream>
using namespace std;

class MyClass {
public:
    ~MyClass() { delete this; }
};

void test() {
    MyClass m;
}

int main() {
    test(); // Segmentation fault 11: "delete and dtor circular reference" casued dump
	return 0;
}