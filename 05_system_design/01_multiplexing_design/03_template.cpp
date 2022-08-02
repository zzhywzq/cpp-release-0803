#include <iostream>
using namespace std;

template<typename T>
T add(T t1, T t2) {
	return t1 + t2;
}

template<typename T>
class MyClass {
public:
	T data_;
};

void test_template_func() {
	cout << add(1, 2) << endl;
	cout << add(1.5, 2.1) << endl;
}

void test_template_class() {
	MyClass<int> m1;
	MyClass<char> m2;
	cout << m1.data_ << endl;
	cout << m2.data_ << endl;
}

int main() {
	test_template_func();
	test_template_class();
	return 0;
}