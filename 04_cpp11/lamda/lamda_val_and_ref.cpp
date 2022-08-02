#include <iostream>
#include <algorithm>
#include <vector>

void test1() {
	std::vector<int> vec = { 1, 2, 3 };
	int total = 0;
	std::for_each(std::begin(vec), std::end(vec), [&](int x) {
		total += x;
	});
	std::cout << "total: " << total << std::endl;
}

void test2() {
	std::vector<int> vec = {1, 2, 3};
	int total = 0;
	std::for_each(std::begin(vec), std::end(vec), [=](int x) {
		// total += x; // compile error: cannot modify val
	});
	std::cout << "total: " << total << std::endl;
}

int main() {
	test1();
	test2();
	return 0;
}