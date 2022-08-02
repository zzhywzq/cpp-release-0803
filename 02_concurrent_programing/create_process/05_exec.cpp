// because c cannot overload, exec contains 6 functions: execl, execle, execlp, execv, execve, execvp
#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
using namespace std;

int test() {
	int status;
	if (fork() == 0) {
		char* argv[5] = { (char*)"ls", (char*)"-l", (char*)"/",NULL };
		// if "exec() >=  0", which means succeed
		// child process will be killed and will not return, exec process will be started and will return
		// essential: exec process replaces child process memory space and start execute: stack, heap, bss, data, text
		if (execv("/bin/ls", argv) < 0) { 
			cout << "error on exec\n";
			exit(0);
		}
	}
	else {
		wait(&status);
		cout << "exec done\n";
	}
	return 0;
}

int main() {
	test();
	return 0;
}