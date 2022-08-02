#include <iostream>
using namespace std;

class MyClass {
public:
    MyClass() = delete;
};

int main() {
    MyClass m; // error
	return 0;
}