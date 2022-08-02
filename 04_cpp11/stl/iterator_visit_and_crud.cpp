#include <iostream>
#include <vector>
#include <list>
using namespace std;

// "erase" returns the iterator following the last removed element
// if u don't use "operator=" after "erase", you may cause core dump
void test_erase() {
	vector<int> vec = { 1, 2, 3, 1 };
	for (auto it = vec.begin(); it != vec.end();) {
		if (*it >= 2) it = vec.erase(it); // continious memory: after erase, current iter and following iters become invalid
		else ++it;
	}
	for (auto it = vec.begin(); it != vec.end(); ++it) cout << *it << " ";
	cout << endl;

	list<int> lst = { 1, 2, 3, 1 };
	for (auto it = lst.begin(); it != lst.end();) {
		if (*it >= 2) it = lst.erase(it); // no continious memory: after erase, current iter become invalid
		else ++it;
	}
	for (auto it = lst.begin(); it != lst.end(); ++it) cout << *it << " ";
	cout << endl;
}

// when "push_back", if vector resize, all iters become invalid
// if not, current iter and following iters become invalid
void test_push_back() {
}

int main() {
	test_erase();
	test_push_back();
	return 0;
}