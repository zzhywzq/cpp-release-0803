#include <iostream>
#include <type_traits>
using namespace std;

struct A {};

class B {};

enum class E {};

union U { class UC {}; };

int main() {
	cout << boolalpha;

	cout << (is_class<A>::value) << ": A\n";
	cout << (is_class<B>::value) << ": B \n";
	cout << (is_class<const B>::value) << ": const B \n";
	cout << (is_class<struct S>::value) << ": struct S (incomplete)\n";
	cout << (is_class<class C>::value) << ": class C (incomplete)\n";

	cout << (is_class<B*>::value) << ": B* \n"; // ptr not a class
	cout << (is_class<B&>::value) << ": B& \n"; // addr not a class
	cout << (is_class<E>::value) << ": E\n"; // enum not a class
	cout << (is_class<E>::value) << ": U\n"; // union not a class, occupies 0 memory
	cout << (is_class<int>::value) << ": int\n"; // pod not a class

	return 0;
}
