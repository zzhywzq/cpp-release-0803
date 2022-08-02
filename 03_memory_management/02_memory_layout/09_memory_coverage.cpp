#include <iostream>
#include <cstring>
using namespace std;

int test() {
	// small end: buffers at stack grow from high addr to low addr
	char buf1[4];
	char buf2[4];
	char buf3[4];
	strcpy(buf2, "BBBB");
	strcpy(buf3, "CCCC");
	cout << buf2 << endl; // buf2 '\0' was covered by buf3
	strcpy(buf1, "AAAA");
	cout << buf2 << endl; // buf2 1st address was covered by '\0'
	return 0;
}

int main() {
	test();
	return 0;
}
