// principle: when the next insertion exceeds 8, fill to 8
#include<iostream>
using namespace std;

struct Data1 {
    char a[5]; 
}Node1;

struct Data2 {
    char a[5]; 
	int b; 
}Node2;

struct Data3 {
    char a[5];
	char c;
	int b;
}Node3;

struct A {
	int a;
	union MyUnion {
		int* ptr;
		short b;
	};
};

struct B {
	char c;
	A obj;
};

int main(){
    cout << sizeof(Node1) << endl; // 5, one member attr no need to fill to 8
	cout << sizeof(Node2) << endl; // 5+(3)+4=12, 5+4=9>8
	cout << sizeof(Node3) << endl; // 5+1+(2)+4=12, 6+4=10>8
	cout << sizeof(B) << endl; // 1+(3)+4=8, union donnot take any place
    return 0;
}
