#include <iostream>
using namespace std;

void func(shared_ptr<int> ptr) {
	// do something...
}

int main() {
	int* p = new int(42);
	func(shared_ptr<int>(p));
    cout << *p << endl; // error, heap data deleted by shared_ptr dtor
	return 0;
}