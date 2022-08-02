// used for ptr cast
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
	// static_cast is used between ptr and void ptr
	int *p1 = static_cast<int*>(malloc(10 * sizeof(int)));
	void *p2 = static_cast<void*>(p1);
		
	// reinterpret_cast is used between ptr and any other type(except void ptr)
	char *p3 = "true";
	float *p3 = reinterpret_cast<float*>(p1);
	p3 = reinterpret_cast<float*>(0X2DF9);
	bool b = *reinterpret_cast<bool *>(p3);

	return 0;
}