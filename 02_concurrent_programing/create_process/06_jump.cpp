#include <iostream>
#include <setjmp.h>
using namespace std;

static jmp_buf jmpbuffer;

static void test(int i, int j) {
	cout << __FUNCTION__ << " " << i << " " << j << endl;
	longjmp(jmpbuffer, 1); // seems like goto
}

int main() {
	int val = 1;
	register int regival = 2;
	if (setjmp(jmpbuffer) != 0) { // return == 0 => mark succeed 
		cout << __FUNCTION__ << " " << val << " " << regival << endl;
		exit(0);
	}
	val = 11; regival = 22;
	test(val, regival); // never returns
	return 0;
}