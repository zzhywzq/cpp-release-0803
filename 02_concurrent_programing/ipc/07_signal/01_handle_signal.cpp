#include <iostream>
#include <signal.h>
using namespace std;

void handler(int sig) {
	if (sig == SIGUSR1) cout << "catch SIGUSR1\n";
}

int main() {
	if (signal(SIGUSR1, handler) == SIG_ERR) cout << "signal SIGUSR1 err\n";
	raise(SIGUSR1); // simulate "kill -s 10 pid", raise SIGUSR1 signal to the process
	return 0;
}