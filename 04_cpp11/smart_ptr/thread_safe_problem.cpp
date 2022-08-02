// the lock in shared_ptr is used to make operator=, dtor and ctor tobe atomic operations
#include <iostream>
#include <thread>
using namespace std;
#define MAX_TIME 8888

void test1() {
    shared_ptr<int> p(new int(1));
    thread t1([&](){
        for (int i = 0; i < MAX_TIME; ++i) (*p)++;
    });
    thread t2([&](){
        for (int i = 0; i < MAX_TIME; ++i) (*p)--;
    });
    t1.join();
    t2.join();
    cout << *p << endl; // result may not be 1
}

void test2() {
    shared_ptr<int> p(new int(1));
    shared_ptr<int> q(p);
    thread t1([&](){
        for (int i = 0; i < MAX_TIME; ++i) (*p)++;
    });
    thread t2([&](){
        for (int i = 0; i < MAX_TIME; ++i) (*q)--;
    });
    t1.join();
    t2.join();
    cout << *p << " " << *q << endl; // result may not be 1
}

int main() {
    test1();
    test2();
	return 0;
}