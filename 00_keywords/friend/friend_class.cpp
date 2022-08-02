// friend relation is unidirectional and cannot be passed or inherited
#include <iostream>
using namespace std;

class MyClass {
private:
    int x = 0;
    int y = 0;
public:
    friend class FriendClass; // friend class
};

class FriendClass {
private:
    MyClass m;
public:
    void func() { cout << m.x + m.y << endl; }
};

int main() {
    FriendClass f;
	f.func();
	return 0;
}