#include <iostream>
using namespace std;

void test() {
	char ch1 = '\0';
	char ch2 = '0';
	char ch3 = 'A';
	char ch4 = 'a';
	cout << (int)ch1 << " " << ch1 << endl; // int: 0,  char:  
	cout << (int)ch2 << " " << ch2 << endl; // int: 48, char: 0
	cout << (int)ch3 << " " << ch3 << endl; // int: 65, char: A
	cout << (int)ch4 << " " << ch4 << endl; // int: 97, char: a
	// operator<<(ostream &, char&): cout char itself
	// operator<<(ostream &, int&): cout asc 
}

int main() {
	test(); 
	return 0;
}