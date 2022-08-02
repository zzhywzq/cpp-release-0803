#include <iostream>
#include <type_traits>
using namespace std;

class Type1 { public: int member_a; };
class Type2 { public: int member_b; };

template <typename T>
void do_something_according_to_class(T t) {
	if (is_same<decltype(t), Type1>::value) cout << "has member_a " << endl;
	if (is_same<decltype(t), Type2>::value) cout << "has member_b " << endl;
}

const int& getRef(const int* p) { return *p; }

int main() {
	cout << boolalpha;

	// pod
	int i = 33;
	decltype(i) j = i * 2;
	cout << "i and j are the same type? " << (is_same<decltype(i), decltype(j)>::value) << '\n';
	cout << "j is int? " << (is_same<decltype(i), int>::value) << '\n';

	// class
	Type1 t1;
	do_something_according_to_class(t1);
	Type2 t2;
	do_something_according_to_class(t2);

	// function
	static_assert(is_same<decltype(getRef), const int&(const int*)>::value);

	return 0;
}