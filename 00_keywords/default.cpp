/*
	default ctor is not same as empty ctor
	B() is same as C(), but not A()
*/

#include <iostream>

class A {
public:
	A() {}
	int i;
	int j;
};

class B {
public:
	B() = default;
	int i;
	int j;
};

class C {
public:
	C(): i(0), j(0) {};
	int i;
	int j;
};

int main()
{
	for (int i = 0; i < 3; ++i) {
		A* pa = new A();
		B* pb = new B();
		C* pc = new C();

		std::cout << pa->i << "," << pa->j << std::endl;
		std::cout << pb->i << "," << pb->j << std::endl;
		std::cout << pc->i << "," << pc->j << std::endl;
		std::cout << std::endl;

		delete pa;
		delete pb;
		delete pc;
	}
	return 0;
}

//0, 0
//0, 0
//0, 0
//
//- 1190379824, 32767
//0, 0
//0, 0
//
//- 1190379824, 32767
//0, 0
//0, 0
