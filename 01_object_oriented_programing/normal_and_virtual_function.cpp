#include <iostream>
using namespace std;

class Father {
public:
	virtual void speak() { cout << "Father speak" << endl; }
	void eat() { cout << "Father eat"  << endl; }
};

class Son :public Father {
public:
	void speak() { cout << "Son speak" << endl; }
	void eat() { cout << "Son eat" << endl; }
};

void test() {
	Son son;
	Father& father = son;
	father.speak(); // Son speak
	father.eat(); // Father eat
}

int main() {
	test();
	return 0;
}