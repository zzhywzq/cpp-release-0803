#include <iostream>
#include <signal.h>
#include <unistd.h>
using namespace std;

void handler(int sig) {
	if (sig == SIGUSR1) cout << "catch SIGUSR1\n";
	else if (sig == SIGUSR2) cout << "catch SIGUSR2\n";
}

int main() {
	if (signal(SIGUSR1, handler) == SIG_ERR) cout << "signal SIGUSR1 err\n";
	if (signal(SIGUSR2, handler) == SIG_ERR) cout << "signal SIGUSR2 err\n";
	sigset_t newmask, oldmask;
	sigemptyset(&newmask);
	sigaddset(&newmask, SIGUSR1);
	sigaddset(&newmask, SIGUSR2);

	// before block, raise signal
	raise(SIGUSR1);
	raise(SIGUSR2);
	raise(SIGUSR1);

	// block newmask sigset, which contains SIGUSR1 and SIGCHLD
	if (sigprocmask(SIG_BLOCK, &newmask, NULL) < 0) cout << "sigprocmask err\n";
	else cout << "SIGUSR1 SIGUSR2 blocked\n";
	
	// after block, raise signal
	raise(SIGUSR1);
	raise(SIGUSR2);
	raise(SIGUSR1); // the same signal will be uniqed after block!!!

	// unblock with oldmask
	if (sigprocmask(SIG_SETMASK, &oldmask, NULL) < 0) cout << "sigprocmask err\n";
	else cout << "SIGUSR1 SIGUSR2 unblocked\n";

	while (1);
	return 0;
}