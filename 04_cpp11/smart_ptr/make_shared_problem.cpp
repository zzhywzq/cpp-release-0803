#include <iostream>
using namespace std;

void test1() {
	int* num = new int(1);
    shared_ptr<int> p(num);
    // p.count_ and p.data_ exist fragment 
}

void test2() {
    auto p = make_shared<int>(1);
    // p.count_ and p.data_ layout close
}

int main() {
	test1();
    test2();
	return 0;
}