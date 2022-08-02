#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
using namespace std;

int test() {
	int status;
	if (fork() == 0) {
		for (int i = 0; i < 3; ++i) cout << "child processn\n";
		exit(0);
	}
	else {
		wait(&status); // block the parent process until the child process finished
		for (int i = 0; i < 3; ++i) cout << "parent processn\n";
	}
	cout << "after\n";
	return 0;
}

int main() {
	test();
	return 0;
}
