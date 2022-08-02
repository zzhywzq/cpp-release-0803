#include <iostream>
#include <vector>
using namespace std;

union MyUnion {
	int num1;
	double num2;
	char num3;
	float num4;
};

int main() {
	MyUnion u;
	vector<MyUnion> vec(2);
	vec[0].num1 = 1;
	vec[1].num2 = 2.0;
	vec[2].num3 = '0';
	cout << vec[0].num1 << " " << sizeof(vec[0]) << endl;
	cout << vec[1].num2 << " " << sizeof(vec[1]) << endl;
	cout << vec[2].num3 << " " << sizeof(vec[2]) << endl;
	return 0;
}
