// used for down cast and up cast
#include <iostream>
using namespace std;

class Dad {};
class Son : public Dad {};

void test(Son* son, Dad* dad) {
	// 1.up cast: period is different
	Dad* dad2 = static_cast<Dad*>(son); // safe: cast at compiling period
	Dad* dad3 = dynamic_cast<Dad*>(son); // safe: cast at running period

	// 2.down cast: error handler is different
	Son* son2 = static_cast<Son*>(dad); // not safe: should check nullptr after down cast
	// Son* son3 = dynamic_cast<Son*>(dad); // not safe: compile err
}

int main() {
	return 0;
}