#include <iostream>
using namespace std;

class Father {
public:
	int attr1; // in class, sub class, outside class
protected:
	int attr2; // in class, sub class
private:
	int attr3; // in class
};

class Son : public Father {
public:
	void func() {
		this->attr1;
		this->attr2;
		this->attr3; // compile error
	}
};

void test() {
	Father f;
	f.attr1;
	f.attr2; // compile error
	f.attr3; // compile error
}

int main() {
	test();
	return 0;
}
