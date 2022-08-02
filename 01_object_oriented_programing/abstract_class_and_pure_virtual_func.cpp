#include <iostream>
using namespace std;

class Base {
public:
	virtual void func() = 0; // a pure virtual func leads to an abstract class
};

class Son :public Base {
public:
	void func() { cout << "override this func, then the class Son is no more an abstract class" << endl; };
};

void test()
{
	// Base base; // compile error: abstract class cannot init an instance
	Son son;
	Base* base = &son;
	base->func();
}

int main() {
	test();
	return 0;
}
