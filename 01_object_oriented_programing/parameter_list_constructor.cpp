#include <iostream>
using namespace std; 

class Base {
public:
	Base(int num, int var) : num_(num), var_(var) {} // compile ok: para list ctr can init const member attrs
	Base() : num_(0), var_(num_) {} // compile warn: init order depends on vars declare order

private:
	int var_;
	const int num_; 
};

int main() {
	return 0;
}