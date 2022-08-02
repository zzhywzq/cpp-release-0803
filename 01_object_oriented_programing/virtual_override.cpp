#include <iostream>
using namespace std;

class Animal {
public:
	int m_Age;
};

class Lion : public Animal {};
class Tiger : public Animal {};
class LionTiger : public Lion, public Tiger {};

class LionV : virtual public Animal {};
class TigerV : virtual public Animal {};
class LionTigerV : public LionV, public TigerV {};

void test() {
	LionTiger lt;
	lt.Lion::m_Age = 1;
	lt.Tiger::m_Age = 2;
	cout << lt.Lion::m_Age << endl;
	cout << lt.Tiger::m_Age << endl;
	// cout << lt.m_Age << endl; // compile error: imbiguous

	LionTigerV ltv;
	ltv.m_Age = 3;
	cout << ltv.m_Age << endl;
}

int main() {
	test();
	return 0;
}
