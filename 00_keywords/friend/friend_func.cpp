#include <iostream>
using namespace std;

class MyClass {
private:
    int x = 0;
    int y = 0;
public:
    friend void func(MyClass& m); // friend func
};

void func(MyClass& m) {
    cout << m.x + m.y << endl; 
}

int main() {
	MyClass m;
    func(m);
	return 0;
}