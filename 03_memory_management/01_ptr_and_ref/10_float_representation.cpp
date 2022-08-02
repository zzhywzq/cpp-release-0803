#include <iostream>
using namespace std;

// diff precision causes diff results
void test1() {
	float f1 = 0.00101;
	float f2 = 0.00102;
	cout << __FUNCTION__ << " " << (abs(f1 - f2) <= 1e-6) << endl; // n equal
	cout << __FUNCTION__ << " " << (abs(f1 - f2) <= 1e-5) << endl; // equal
}

void test2() {
	float f1 = 0.001000000001;
	float f2 = 0.001000000002;
	cout << __FUNCTION__ << " " << (abs(f1 - f2) <= 1e-100) << endl; // equal: beyond the ability of os expression
}

int main() {
	test1();
	test2();
	return 0;
}