#include <iostream>
using namespace std;

class Person {
public:
	Person(int var) : var_(var) {}
	void func_1() {}
	void func_2() const {
		cout << var_ << endl; // const func can read all attrs
		// var_ = 100; // error: const func cannot modify any attrs
		// func_1(); // error: const func cannot call non-const func
	}
	int var_;
};

int main() {
	Person p1(1);
	return 0;
}
