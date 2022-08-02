#include <iostream>
using namespace std;

class MyClass {
public:
    void func1() {}
    virtual void func2() {};
    void func_delete() { delete this; }
};

int main() {
    MyClass *m = new MyClass();
    m->func_delete();
    cout << "func_delete end" << endl;
    m->func1(); // ok
    cout << "func1 end" << endl;
    m->func2(); // Segmentation fault 11: the memory of "vptr" has been deleted
    cout << "func2 end" << endl;
	return 0;
}