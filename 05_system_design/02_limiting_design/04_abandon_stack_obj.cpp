#include <unistd.h>

class A {
private:
    A() {}
    ~A() {}
public:
    static A* create() {
        return new A();
    }
    void destory() {
        delete this;
    }
};

int main() {
    // A a1; // compile error
    A* a2 = A::create();
    a2->destory();
    return 0;
}