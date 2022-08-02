#include <iostream>
#include <string>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

void readMemory() {
	char *fd_name = (char*)"/opt/my_pipe";
	int fd = open(fd_name, O_RDONLY, 00777);
	if (fd < 0) cout << "open file error" << endl;

	// read
	char recvbuf[BUFSIZ];
	read(fd, recvbuf, BUFSIZ);
	cout << recvbuf << endl;

	close(fd);
}

int main() {
	readMemory();
	return 0;
}