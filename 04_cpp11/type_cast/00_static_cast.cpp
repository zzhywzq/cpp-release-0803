#include <vector>
#include <iostream>

int main() {
	// lvalue to xvalue (which implements move and forward)
	std::vector<int> v0{ 1,2,3 };
	std::vector<int> v2 = static_cast<std::vector<int>&&>(v0);
	std::cout << "after move, v0.size() = " << v0.size() << '\n';
	return 0;
}