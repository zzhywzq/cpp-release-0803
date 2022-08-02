#include <iostream>
using namespace std;

void func(int num1, int num2) {
    cout << num1 + num2 << endl;
	return;
}

void func(int num) {
    cout << num << endl;
	return;
}

void func(char* ch) {
    cout << ch[0] << endl;
	return;
}

int main() {
	int num1 = 1;
    int num2 = 2;
    char* ch = (char*)"abc";
	func(num1, num2);
    func(num1);
    func(ch);
	return 0;
}