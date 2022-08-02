#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <fcntl.h>
using namespace std;

void writeMemory() {
	char *fd_name = (char*)"/opt/my_pipe";
	int fd = open(fd_name, O_CREAT | O_RDWR | O_TRUNC, 00777);
	if (fd < 0) cout << "create file error" << endl;

	// write
	char sendbuf[BUFSIZ] = "abc";
	write(fd, sendbuf, strlen(sendbuf) + 1);
	this_thread::sleep_for(chrono::seconds(10));

	close(fd);
}

int main() {
	writeMemory();
	return 0;
}