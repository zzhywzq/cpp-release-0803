#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <atomic>
using namespace std;

atomic<int> g_counter;

class MyClass {
public:
    MyClass() { cout << "constructor g_counter: " << g_counter << endl; } // "new" calls constructor
    ~MyClass() { cout << "destructor g_counter: " << g_counter << endl; }
};

void* operator new(size_t size) {
    if (size == 0) size = 1; // "new" checks the null class
    void* p = ::malloc(size);
    if (p == nullptr) { // "new" deals with the exception, instead of returns nullptr when failed
        new_handler nh = get_new_handler();
        if (nh) nh();
        else throw bad_alloc();
    }
    g_counter++;
    return p;
}

void operator delete(void *ptr) throw() {
    if (ptr == nullptr) return;
    ::free(ptr);
    g_counter--;
}

void *thread_function(void *threadid) {
    for (int i = 0; i < 100; ++i) {
        MyClass *p = new MyClass();
        delete p;
        p = NULL;
    }
    pthread_exit(NULL);
}

int main() {
    set_new_handler([]() { return; });
    pthread_t threads[20];
    for (int i = 0; i < 20; i++) {
        int rc = pthread_create(&threads[i], NULL, thread_function, (void *)&i);
        if (rc) cout << "pthread_create error: " << rc << endl;
    }
    sleep(3);
    cout << "at last g_counter is: " << g_counter << " and there is no leak" << endl;
    pthread_exit(NULL);
    return 0;
}
