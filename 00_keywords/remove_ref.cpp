#include <iostream>
#include <type_traits>
using namespace std;

int main() {
	cout << boolalpha;
	cout << "remove_reference<int>::type is int? " << is_same<int, remove_reference<int>::type>::value << '\n';
	cout << "remove_reference<int&>::type is int? " << is_same<int, remove_reference<int&>::type>::value << '\n';
	cout << "remove_reference<int&&>::type is int? " << is_same<int, remove_reference<int&&>::type>::value << '\n';
	cout << "remove_reference<const int&>::type is const int? " << is_same<const int, remove_reference<const int&>::type>::value << '\n';
	return 0;
}
