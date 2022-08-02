#include <iostream>
#include <unistd.h>
using namespace std;

int test() {
	if (fork() == 0) { // fork(): child process return 0
		for (int i = 0; i < 3; ++i) cout << "child processn\n";
	}
	else { // fork(): parent process return child process pid
		for (int i = 0; i < 3; ++i) cout << "parent processn\n";
	}
	cout << "after\n";
	return 0;
}

int main() {
	test();
	return 0;
}