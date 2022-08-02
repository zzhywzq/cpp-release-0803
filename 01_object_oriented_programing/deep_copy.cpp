/*
	call dtor twice, maybe cause core dump
	if os has already alloc the deleted memory to another progress, the 2nd delete will cause dump
	if not, the 2nd delete will not cause dump
*/
#include <iostream>
using namespace std;

class Person {
public:
	Person(int age, int height) {	
		m_age = age;
		m_height = new int(height);
	}
	Person(const Person& p) {
		m_age = p.m_age;
		m_height = new int(*p.m_height);
	}
	~Person() {
		if (nullptr != m_height) {
			cout << "delete addr " << m_height << endl;
			delete m_height; // call dtor twice, deleted memory is not same
		}
	}
private:
	int m_age;
	int* m_height;
};

void test() {
	Person p1(18, 180);
	Person p2(p1);
}

int main() {
	test();
	return 0;
}
