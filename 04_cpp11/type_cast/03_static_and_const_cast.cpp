// used for add const or remove const
#include <iostream>
using namespace std;

int main() {
	const int n = 100;
	int *p = const_cast<int*>(&n); // remove const
	*p = 234; // modify succeed
	cout << "n = " << n << endl;
	cout << "*p = " << *p << endl;

	const int *q = static_cast<int*>(p); // add const
	// *q = 678; // compile error: cannot be modify
	cout << "*q = " << *q << endl;
	return 0;
}