// const and non-const obj cannnot call the others function
#include <iostream>
using namespace std;

class ConstOverRide {
public:
	void func() {
		cout << "void func()" << endl;
	}
	void func() const {
		cout << "void func() const" << endl;
	}
};

void test() {
	ConstOverRide c1;
	c1.func();
	const ConstOverRide c2;
	c2.func();
}

int main() {
	test();
	return 0;
}
