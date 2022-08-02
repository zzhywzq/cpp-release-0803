#include <iostream>
using namespace std;

void* my_memcpy(void* p_dest, const void* p_src, size_t n) {
    if (!p_dest || !p_src) return p_dest;
    int word_num = n >> 2; // using 4bytes copy is faster than 1byte
    int remain_num = n - (word_num << 2); // remain use 1byte copy

    int* p_int_dest = reinterpret_cast<int*>(p_dest);
    const int* p_int_src = reinterpret_cast<const int*>(p_src);
    while (word_num--) *p_int_dest++ = *p_int_src++;

    char* p_char_dest = reinterpret_cast<char*>(p_int_dest);
    const char* p_char_src = reinterpret_cast<const char*>(p_int_src);
    while (remain_num--) *p_char_dest++ = *p_char_src++;
    return p_dest;
}

void test() {
	uint16_t src[4] = { 0x0001, 0x0002, 0x0003, 0x0004 };
	uint16_t dest[4] = { 0x0006, 0x0007, 0x0008, 0x0009 };
    my_memcpy(dest, &src[1], 3 * sizeof(uint16_t));
    for (auto item : dest) cout << item; // expect: 2349, and actual:2349
    cout << endl;
    my_memcpy(&dest[1], dest, 3 * sizeof(uint16_t));
    for (auto item : dest) cout << item; // expect: 2234, but actual: 2233, solution: memmove
    cout << endl;
}

int main() {
    test();
	return 0;
}