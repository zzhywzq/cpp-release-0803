// uint8_t [0,127],[128,255]
// int8_t  [0,127],[-128,-1]
#include <iostream>
using namespace std;

void test1() {
    uint8_t u_num = 127;
    int8_t num = u_num;
    cout << (int)num << endl; // 127
}

void test2() {
    uint8_t u_num = 128;
    int8_t num = u_num;
    cout << (int)num << endl; // -128
}

int main() {
    test1();
    test2();
    return 0;
}