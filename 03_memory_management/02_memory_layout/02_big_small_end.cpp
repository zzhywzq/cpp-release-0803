#include <iostream>
#include <string>
using namespace std;

bool is_small_end() {  	
	uint32_t a = 0x12345678;
    char* c = (char*)&a; // use address instead of value convert -- "char c = (char)a;", for it's always true
    return ((c[0] == 0x78) && (c[1] == 0x56) && (c[2] == 0x34) && (c[3] == 0x12));
}

int main() {
	cout << "is_small_end: " << is_small_end() << endl;
	// small_end：stack vars higher addr means lower bytes, "0x78" first, "0x56" second
	return 0;
}
