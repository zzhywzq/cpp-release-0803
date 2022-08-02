#include <iostream>
#include <unistd.h>
using namespace std;

int test() {
	if (fork() == 0) {
		for (int i = 0; i < 3; ++i) cout << "child processn\n";
		// auto temp = exit(0); // compile error: exit() has no return value
		exit(0); // kill child process here
	}
	else {
		for (int i = 0; i < 3; ++i) cout << "parent processn\n";
	}
	cout << "after\n";
	return 0;
}

int main() {
	test();
	return 0;
}