#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(void) {
	int fd[2];
	if ((pipe(fd)) < 0) cout << "pipe failedn";
	char buf[BUFSIZ] = "hello my bro!";
	pid_t pid;

	if ((pid = fork()) < 0) cout << "fork failedn";
	else if (pid == 0) {
		close(fd[0]); // child process close itself read port (fd[0])
		write(fd[1], buf, strlen(buf)); // write to pipe
		exit(0);
	}

	if ((pid = fork()) < 0) cout << "fork failedn";
	else if (pid > 0) {
		close(fd[0]);
		close(fd[1]);
		exit(0);
	}
	else if (pid == 0) {
		close(fd[1]); // child process close itself write port (fd[1])
		int len = read(fd[0], buf, BUFSIZ); // read from pipe
		if (len < 0) cout << "process failed when read a pipen";
		else cout << buf << endl;
		exit(0);
	}
	return 0;
}