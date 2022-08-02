#include <iostream>
using namespace std;

class Father {
public: 
	Father() { cout << "Father construct\n"; }
	~Father() { cout << "Father destruct\n"; }
};

class Son :public Father {
public:
	Son() { cout << "Son construct\n"; }
	~Son() { cout << "Son destruct\n"; }
};

void test() {
	Son son; // father at first
}

int main() {
	test();
	return 0;
}
