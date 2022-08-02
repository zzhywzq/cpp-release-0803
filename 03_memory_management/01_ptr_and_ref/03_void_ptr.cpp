#include <iostream>
using namespace std;

void test(void* p) {
	int * pdst = (int *)p; // cast to the type u need
	*pdst = 3;
}

int main() {
	int num = 0;
	int *p = &num;
	test(p);
	cout << *p << endl;
	return 0;
}