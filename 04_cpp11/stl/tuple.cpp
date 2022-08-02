#include <iostream>
#include <tuple>
using namespace std;

void test() {
	tuple<int, char, double> mytuple(1,'a',0.3);
	int myint;
	tie(myint, ignore, ignore) = mytuple;
	cout << myint << endl; // 1
	cout << get<2>(mytuple) << endl; // 0.3
}

int main() {
	test();
	return 0;
}