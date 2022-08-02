#include <iostream>
using namespace std;

class Dad {
public:
    ~Dad() { cout << "Dad::destrutor" << endl; }
};

class Son : public Dad {
public:
    ~Son() { cout << "Son::destrutor" << endl; }
};

class Dad2 {
public:
    virtual ~Dad2() { cout << "Dad2::destrutor" << endl; }
};

class Son2 : public Dad2 {
public:
    ~Son2() { cout << "Son2::destrutor" << endl; }
};

int main() {
    Dad* p = new Son;
    delete p; // ~Dad() was called by delete, but ~Son() wasn't
    cout << endl;
    Dad2* q = new Son2;
    delete q;
    return 0;
}
