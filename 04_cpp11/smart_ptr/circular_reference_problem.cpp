#include <iostream>
using namespace std;

template<typename T>
struct WrongCase {
    WrongCase(T value) :_value(value) {}
    ~WrongCase() {}
    T _value;
    shared_ptr<WrongCase<T>> _prev;
    shared_ptr<WrongCase<T>> _next;
};

void test1() {
    shared_ptr<WrongCase<int>> p1(new WrongCase<int>(1));
    shared_ptr<WrongCase<int>> p2(new WrongCase<int>(2));
    p1->_next = p2;
    p2->_prev = p1;
    cout << p1.use_count() << " " << p2.use_count() << endl; // 2
}

template<typename T>
struct RightCase {
    RightCase(T value) :_value(value) {}
    ~RightCase() {}
    T _value;
    weak_ptr<RightCase<T>> _prev; // when members cause circular ref, should use weak_ptr
    weak_ptr<RightCase<T>> _next;
};

void test2() {
    shared_ptr<RightCase<int>> p1(new RightCase<int>(1));
    shared_ptr<RightCase<int>> p2(new RightCase<int>(2));
    p1->_next = p2;
    p2->_prev = p1;
    cout << p1.use_count() << " " << p2.use_count() << endl; // 1
}

int main() {
    while(true) {
        // test1(); // open the code to run test1 will cause memory leak
        test2();
    }
    return 0;
}