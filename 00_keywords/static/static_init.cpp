// Q: how to know a static var has been inited?
// A: alloc a piece of memory nearby for identification
#include <iostream>
using namespace std;

class A {
public:
	A() { cout << "AAA\n"; }
};

static int num; // init at compile

static A a1; // init at load (because need ctor)

void func() { static A a2; } // init at function call (the thread safe problem was solved at c++11)

int main() {
	cout << "main start\n";
	func();
	return 0;
}