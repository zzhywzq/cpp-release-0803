#include <iostream>
using namespace std;

class Base {
public:
	Base() { cout << "Base construct\n"; }
	~Base() { cout << "Base destruct\n"; }
};

void test1() {
	Base b;
	cout << "named object do exists\n";
}

void test2() {
	Base();
	cout << "anonymous object has been deleted\n";
}

int main() {
	test1();
	cout << "\n";
	test2();
	return 0;
}
