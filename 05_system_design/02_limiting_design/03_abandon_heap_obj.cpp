#include <unistd.h>

class A {
private:
    void* operator new(size_t t) = delete;
    void operator delete(void* ptr) = delete;
public:
    A() {}
    ~A() {}
};

int main() {
    A a1;
    // A* a2 = new A(); // compile error
    return 0;
}