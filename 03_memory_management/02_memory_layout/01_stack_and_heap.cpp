#include <iostream>
using namespace std;

int *test1() {
    int a = 10;
	int *ptr = &a;
	return ptr;
}

int *test2() {
    int* ptr = new int(10);
	return ptr;
}

void test() {
	int *p1 = test1();
	int *p2 = test2();
    cout << "test1: " << *p1 << endl; // got a mess
	cout << "test2: " << *p2 << endl; // got value 10
}

int main() {
	test();
	return 0;
}
