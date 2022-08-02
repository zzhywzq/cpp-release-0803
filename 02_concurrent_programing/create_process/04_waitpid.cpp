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
		waitpid(-1, &status, 0); // -1: wait any child process, 0: block, this is same as wait(&status)
		for (int i = 0; i < 3; ++i) cout << "parent processn\n";
	}
	cout << "after\n";
	return 0;
}

int test2() {
	int status;
	int child_pid;
	if ((child_pid = fork()) == 0) {
		for (int i = 0; i < 3; ++i) cout << "child processn\n";
		exit(0);
	}
	else {
		waitpid(child_pid, &status, WNOHANG); // child_pid: wait specific child process, WNOHANG: non-block
		for (int i = 0; i < 3; ++i) cout << "parent processn\n";
	}
	cout << "after\n";
	return 0;
}

int main() {
	test();
	test2();
	return 0;
}
