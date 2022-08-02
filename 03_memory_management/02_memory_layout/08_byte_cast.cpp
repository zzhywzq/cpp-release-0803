#include <iostream>
using namespace std;

void func1(char* ptr) { *ptr = 'A'; }
void func2(int* ptr) { *ptr = 48; }

void test_ok() {
	int num = 1;
	func1((char*)&num); // 65: high addr 1 byte was changed to char 'A', means int 65(small end)
	cout << __FUNCTION__ << " " << num << endl;
}

void test_wrong_1() {
	char ch = '1';
	int num = 1;
	func2((int*)&ch);
	cout << __FUNCTION__ << " " << ch << endl; // 0: 1 byte of ch was changed to int 48, means char '0'
	cout << __FUNCTION__ << " " << num << endl; // 0: high addr 3 bytes of num was changed to int 0
}

void test_wrong_2() {
	char ch = '1';
	func2((int*)&ch); // stack smashing: only one byte was given at stack, using 4 bytes is forbbiden
	cout << __FUNCTION__ << " " << ch << endl;
}

int main(int argc, char** argv) {
	test_ok();
	test_wrong_1();
	test_wrong_2();
	return 0;
}