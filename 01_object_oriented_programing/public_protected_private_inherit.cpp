#include <iostream>
using namespace std;

class Father {
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};

class Son1 :public Father {};
class Son2 :protected Father {};
class Son3 :private Father {};

void test() {
	Son1 s1;
	s1.m_A;
	cout << "sizeof Son = " << sizeof(s1) << endl; // 12: protected and private members are not available for s1, but still alloc memory
	Son2 s2;
	// s2.m_A; // compile error: Son2.m_A is protected, instead of public
	// sub class member access permission = min(parent class member access permission，inherit permission)
}

int main() {
	test();
	return 0;
}