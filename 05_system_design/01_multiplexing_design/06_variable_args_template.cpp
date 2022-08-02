#include <iostream>
using namespace std;

int get(int a) { return a + a; }
int get(char a) { return a + a; }
string get(string a) { return a + a; }

void test() { cout << "no args" << endl; } // called at last time 

template <class T, class ...Args>
void test(T value, Args... args) {
	cout << "value: " << value << endl;
	cout << "sizeof args: " << sizeof...(args) << endl; // count of args. every recursion -1
	cout << "get value: " << get(value) << endl << endl;
	test(args...);
}

int main() {
	test(std::string("sort"), 1, 'A');
	return 0;
}