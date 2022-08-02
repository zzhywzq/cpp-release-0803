#include <iostream>
#include <signal.h>
using namespace std;

int main() {
	if (signal(SIGINT, SIG_IGN) == SIG_ERR) cout << "signal SIGINT err\n"; // ignore SIGINT, then "ctr c" cannot kill the program
	while (1);
	return 0;
}