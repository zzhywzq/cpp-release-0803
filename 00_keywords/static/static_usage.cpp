#include <iostream>
using namespace std;

class A {
public:
	static void f() {}; // static member func: don't need this ptr, used for static member var
private:
    static int data_; // static member var: don't need this ptr, belongs to class, not a object
};

static int count; // static global var: cannot be extern(but still in data partition)
static void f() {} // static global func: cannot be extern(but still in test partition)

int main() {
	static int num = 0; // static local var: change memory partition(stack -> data)
	return 0;
}