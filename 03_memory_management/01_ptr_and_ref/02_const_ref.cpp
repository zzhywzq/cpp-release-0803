#include <iostream>
using namespace std;

void test() {
	int num = 3;
	const int &rf = num;
	num = 1; // compile ok��u can update the stack memory by num
	// rf = 1; // compile error��u cannot update the stack memory by rf
}

int main() {
	test();
	return 0;
}