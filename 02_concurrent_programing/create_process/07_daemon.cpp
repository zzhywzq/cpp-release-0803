#include <unistd.h>
#include <signal.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
#include <cstdlib>

void init_daemon() {
	int pid;
	if ((pid = fork()) > 0) exit(0);
	setsid(); // the process starts a new session, and become the root node of the process tree
	if ((pid = fork()) > 0) exit(0); // prevent process opening new terminal
	for (int i = 0; i < NOFILE; ++i) close(i); // close fd and avoid resource consumption
	chdir("/tmp"); // redirect logs or dumps to specific directories such as "/tmp"
	umask(0); // reset default permission of users
	return;
}

void do_sth() {
	while (1) {
		FILE* fp = fopen("test.log", "a");
		if (fp >= 0) {
			time_t t = time(0);
			fprintf(fp, "I'm here at %s", asctime(localtime(&t)));
			fclose(fp);
		}
		sleep(1);
	}
}

int main() {
	init_daemon();
	do_sth();
	return 0;
}