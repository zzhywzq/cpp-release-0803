#include <iostream>
#include <vector>
using namespace std;

vector<int> test() {
	vector<int> vec;
	return vec; // compiler use rvo to avoid copy here
}

int main() {
	vector<int> result = test();
	return 0;
}
