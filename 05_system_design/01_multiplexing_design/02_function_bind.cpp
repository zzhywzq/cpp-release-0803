#include <functional>
#include <iostream>

struct Foo {
	Foo(int num) : num_(num) {}
	void print_add(int i) const { std::cout << num_ + i << '\n'; }
	int num_;
};

void print_num(int i) {
	std::cout << i << '\n';
}

int main() {
	std::function<void(int)> f_display = print_num; 
	f_display(-9);

	std::function<void()> f_display_42 = []() { print_num(42); };
	f_display_42();

	std::function<void()> f_display_31337 = std::bind(print_num, 31337);
	f_display_31337();

	const Foo foo(888);
	using std::placeholders::_1;

	std::function<void(int)> f_add_display2 = std::bind(&Foo::print_add, foo, _1);
	f_add_display2(2);

	std::function<void(int)> f_add_display3 = std::bind(&Foo::print_add, &foo, _1);
	f_add_display3(3);
}