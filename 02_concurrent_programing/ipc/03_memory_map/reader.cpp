#include <iostream>
#include <string>
#include <string.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
using namespace std;

struct MyData {
	char name[20];
	int age;
};

void readMemory() {
	char *shared_file_name = (char*)"/opt/my_shared_memory";
	int fd = open(shared_file_name, O_RDONLY, 00777);
	if (fd < 0) cout << "open file error" << endl;

	size_t read_size = sizeof(MyData);

	// map file to memory
	void *p = mmap(NULL, read_size, PROT_READ, MAP_SHARED, fd, 0);
	MyData *share_buffer = (MyData *)p;
	cout << share_buffer->name << " " << share_buffer->age << endl;

	// unmap and close
	munmap(p, read_size);
	close(fd);
}

int main() {
	readMemory();
	return 0;
}