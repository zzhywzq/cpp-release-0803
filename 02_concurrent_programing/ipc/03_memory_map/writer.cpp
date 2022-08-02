#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

struct MyData {
	char name[20];
	int age;
};

void writeMemory() {
	char *shared_file_name = (char*)"/opt/my_shared_memory";
	int fd = open(shared_file_name, O_CREAT | O_RDWR | O_TRUNC, 00777);
	if (fd < 0) cout << "create file error" << endl;

	MyData share_buffer = { "Tom", 18 };
	size_t write_size = sizeof(share_buffer);
	ftruncate(fd, write_size); // resize fd to write_size

	// map memory to file
	void *p = mmap(NULL, write_size, PROT_WRITE, MAP_SHARED, fd, 0);
	memcpy(p, &share_buffer, write_size);
	this_thread::sleep_for(chrono::seconds(10));

	// unmap and close
	munmap(p, write_size);
	close(fd);
}

int main() {
	writeMemory();
	return 0;
}