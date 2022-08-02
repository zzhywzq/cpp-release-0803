#include <iostream>
#include <string.h>
using namespace std;

void test_assignment() {
	char* a = (char*)"string1";
	char b[] = "string2";
	a = b;
	// b = a; // compile error: for char b[] <=> char* const b
}

// u need to know if it's an arr or a ptr
void test_array_and_ptr() {
	cout << endl << "---------test_array_and_ptr:---------" << endl;

	char a[10];
	char* b[10];
	char c[10][10];
	char** d;
	char* e[10][10];
	char** f[10][10];
	cout << sizeof(a) << endl; // 10:  1-d-array, element char
	cout << sizeof(b) << endl; // 80:  1-d-array, element ptr
	cout << sizeof(c) << endl; // 100: 2-d-array, element char
	cout << sizeof(d) << endl; // 8:   2-rank-ptr, no element
	cout << sizeof(e) << endl; // 800: 2-d-array, element ptr
	cout << sizeof(f) << endl; // 800: 2-d-array, element 2-rank-ptr
}

// "strlen" stops when meets '\0', "sizeof" returns continuous memory size of specified type
void test_sizeof_and_strlen() {
	cout << endl << "---------test_sizeof_and_strlen:---------" << endl;

	char str[100] = "abcde";
	cout << sizeof(str) << endl; // 100
	cout << strlen(str) << endl; // 5

	char str1[] = "abcde";
	cout << sizeof(str1) << endl; // 6
	cout << strlen(str1) << endl; // 5

	char str2[] = "\0abcde";
	cout << sizeof(str2) << endl; // 7
	cout << strlen(str2) << endl; // 0

	char str3[] = { 'a', 'b', 'c', 'd', 'e'}; // no '\0'
	cout << sizeof(str3) << endl; // 5
	cout << strlen(str3) << endl; // depends on '\0' of str4

	char* str4 = (char*)"abcde";
	cout << sizeof(str4) << endl; // 8
	cout << strlen(str4) << endl; // 5
}

int main() {
	test_assignment();
	test_array_and_ptr();
	test_sizeof_and_strlen();
	return 0;
}