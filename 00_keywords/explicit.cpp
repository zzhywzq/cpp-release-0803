// ctors with more than 1 args do not need explicit, because it's impossible to happen implicit conversion
#include <iostream>
#include <string>
using namespace std;

class String1 {
public:
	String1 (int size) {
		len_ = size;
		str_ = new char(len_ + 1);
	}
private:
	int len_;
	char* str_;
};

class String2 {
public: 
        explicit String2 (int size) {
                len_ = size;
                str_ = new char(len_ + 1);
        }
private:
        int len_;
        char* str_;
};

int main() {
	String1 str1 = '0'; // call String1(int size), alloc 48 bytes, which is misleading for user means str = "0" originally
	String2 str2 = '0'; // avoid implicit conversion to prohibit the misleading code generated
	return 0;
}
