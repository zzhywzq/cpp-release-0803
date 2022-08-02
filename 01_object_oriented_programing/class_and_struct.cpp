#include <iostream>
using namespace std;

class Person1 {
	int attr;
};

struct Person2 {
	int attr;
};

void test() {
	Person1 p1;
	p1.attr; // compile error: class default private

	Person2 p2;
	p2.attr; // struct default public
}

int main() {
	test();
	return 0;
}
