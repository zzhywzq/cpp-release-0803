#include <vector> 
#include <iostream> 
using namespace std;

void test1() {
    vector<int> vec;
	vec.resize(100); // size_ = 100 (same as vec.resize(100, 0))
    cout << vec.size() << endl; // 100
}

void test2() {
    vector<int> vec;
	vec.reserve(100); // max_size_ = 100
    cout << vec.size() << endl; // 0
}

int main() {
	test1();
    test2();
    return 0;
}