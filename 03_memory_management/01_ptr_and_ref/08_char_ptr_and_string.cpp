#include <iostream>
#include <string>
using namespace std;

void test1(char* dst) { // char *dst <=> string dst
	dst = (char*)"123";
}

void test2(char*& dst) { // char *&dst <=> string& dst
	dst = (char*)"123";
}

void test3() {
	char* ch = (char*)"string";
	string str = ch;
}

void test4() {
	string str = "string";
	char* ch = (char*)str.c_str();
}

int main() {
	char* ch1 = (char*)"abc";
	test1(ch1);
	cout << ch1 << endl;
	char* ch2 = (char*)"abc";
	test2(ch2);
	cout << ch2 << endl;

	test3();
	test4();
	return 0;
}