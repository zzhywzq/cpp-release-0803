// void universal_refference(T t): problem is "to copy T is not efficient"
// void universal_refference(T& t): problem is "only lvalue_ref is valid, rvalue_ref is invalid"
// void universal_refference(T&& t): problem is "rvalue is handled as lvalue_ref"
// void perfect_forward(T&& t): problems all solved 

#include<iostream>
using namespace std;

void Fun(int& x) { cout << "lvalue_ref" << endl; }
void Fun(int&& x) { cout << "rvalue_ref" << endl; }

template<class T>
void universal_refference(T&& t) {
	Fun(t);
}

template<class T>
void perfect_forward(T&& t) {
	Fun(forward<T>(t));
}

int main() {
	int a = 5;

	universal_refference(a);
	universal_refference(3); // rvalue is handled as lvalue_ref

	perfect_forward(a);
	perfect_forward(3);  // rvalue is handled as rvalue_ref

	return 0;
}
