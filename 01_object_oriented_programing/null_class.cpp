#include <iostream>
using namespace std;

// when you define a null class, compiler implements 6 functions by default for your next calling
// no move constructor, no functor, no operator*, no operator<<
class TestClass {
public:
	TestClass() { cout << "constructor" << endl; }
	~TestClass() { cout << "destructor" << endl; }
	TestClass(const TestClass& m) { cout << "copy constructor" << endl; }
	TestClass& operator=(const TestClass& m) {
		cout << "operator=" << endl;
		return *this;
	}
	TestClass* operator&() {
		cout << "operator&" << endl;
		return this;
	}
	const TestClass* operator&() const {
		cout << "const operator&" << endl;
		return this;
	}
};

int main()
{
	TestClass m1; // call constructor
	const TestClass m2(m1); // call copy constructor
	TestClass m3 = m1; // m3 not inited, call copy constructor
	m3 = m1; // m3 inited, call operator=
	&m2; // call const operator&
	&m3; // call operator&
	cout << sizeof(m1) << endl; // for null class obj, 1 byte is used to distinguish from other objs in memory
	return 0;
}
