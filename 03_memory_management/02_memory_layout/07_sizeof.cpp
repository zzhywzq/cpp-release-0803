#include <iostream>
using namespace std;

template <typename T>
int my_sizeof(const T &t) {
	// "+" is T& operator+(), if T is int, &t + 1 moves 1 int distance, which is 1 * 4
	// "-" is char& operator-(), a - b always get (a - b) * 1 bytes
    return (char *)(&t + 1) - (char *)&t;
}

int main() {
	char var1 = 'a';
	int var2 = 1;
	float var3 = 0.1;
	double var4 = 0.01;
	char* var5 = &var1;
	string var6 = "this is a string";

	cout << my_sizeof(var1) << endl; // char 1
	cout << my_sizeof(var2) << endl; // int 4
	cout << my_sizeof(var3) << endl; // float 4
	cout << my_sizeof(var5) << endl; // ptr 8
	cout << my_sizeof(var6) << endl; // str 32
    return 0;
}