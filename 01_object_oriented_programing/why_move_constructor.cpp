#include <iostream>
using namespace std;

class Person {
public:
	Person(int height) : m_height(new int(height)) {}
	Person(const Person& p) { // deep copy to prevent the same heap addr double free
		m_height = new int(*p.m_height);
	}
	Person(Person&& p) { // avoid new operation consume time
		m_height = p.m_height;
		p.m_height = nullptr;
	}
	~Person() {
		if (nullptr != m_height) {
			cout << "destructor " << m_height << endl;
			delete m_height;
		}
	}
private:
	int* m_height;
};

void test() {
	Person p1(180);
	Person p2(p1);
	Person p3(move(p1));
}

int main() {
	test();
	return 0;
}