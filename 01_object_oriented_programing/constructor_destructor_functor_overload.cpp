#include <iostream>
using namespace std;

class A {
public:
	A() {};
	A(int num) {}; // constructor can be overloaded

	~A() {};
	// ~A(int num) {}; // compile error: destructor can not be overloaded

	void operator()(const string& text) { cout << text << endl; }
	void operator()(const int v1, const int v2) { cout << v1 + v2 << endl; } // functor can be overloaded
};

int main() {
	A a;
	// named object call
	a("hello world"); 
	a(100, 100);
	// anonymous object call
	A()("hello world");
	A()(100, 100);
	return 0;
}