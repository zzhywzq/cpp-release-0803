#include<iostream>
using namespace std;

void test1() {
	char* str = nullptr; // str points to 0
	
	char x = 'x';
	str = &x; // str points to stack segmentation
	*str = 'a'; // ok
	cout << *str << endl;

	str = (char*)"xxx"; // str points to data segmentation
	*str = 'b'; // error: cannot change data segmentation
	cout << *str << endl;
}

int main() {
	test1();
	return 0;
}