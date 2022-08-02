#include <iostream>
using namespace std;

void test() {
	int a = 10;
	&a; // correct: lvalue can get addr
	// &10 // error: rvalue can not get addr
	int &b = a; // lvalue referrence
	int &&c = 10; // rvalue referrence
}

int main() {
	test();
	return 0;
}