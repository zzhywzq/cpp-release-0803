#include <iostream>
using namespace std;

void func(void* ptr) {
	cout << "func ptr" << endl;
}

void func(int i) {
	cout << "func i" << endl;
}

int main() {
	// func(NULL); // compile error for ambiguous: #define NULL 0, NULL is a macro, which equals to zero
	func(nullptr); // reason of nullptr is preferred : nullptr is a ptr, which can be cast to any type ptr
	return 0;
}