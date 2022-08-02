#include<iostream>
using namespace std;

void test() {
	int *p; // not init => dangling ptr
	{
		int num = 1;
		p = &num;
	}
	// inited but released => wild ptr
}

int main(){
    test();
	return 0;
}


