#include <iostream>
using namespace std;

void test() {
	int num = 3;
	int *ptr = &num;
	int &ref = num;
	// int &ref; // compile error: ref must be inited when declare

	cout << &num << endl;
	cout << &ref << endl; // ref addr is same as num addr
	cout << ptr << endl; // ptr value is same as num addr
	cout << &ptr << endl << endl; // ptr addr is diff from num addr

	cout << num << endl;
	cout << *ptr << endl;
	cout << ref << endl;
}

int main() {
	test();
	return 0;
}