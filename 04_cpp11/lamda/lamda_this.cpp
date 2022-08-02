#include <iostream>
#include <algorithm>
#include <vector>

class TestClass
{
public:
	void hello() { std::cout << "test hello" << std::endl; };
	void lambda() {
		auto fun = [this] { this->hello(); };
		fun();
	}
};

void test() {
	TestClass t;
	t.lambda();
}

int main() {
	test();
	return 0;
}