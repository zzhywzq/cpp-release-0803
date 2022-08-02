#include <iostream>
using namespace std;

void test1() {
    int m = 1000;
    long res = static_cast<long>(m); // safe
    cout << (int)res << endl;
}

void test2() {
    int m = 1000;
    char res = static_cast<char>(m); // may lost data
    cout << (int)res << endl;
}

int main() {
    test1();
    test2();
    return 0;
}