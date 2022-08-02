#include <iostream>
using namespace std;

template <typename T>
class SharedPtr {
public:
    explicit SharedPtr(T *ptr = nullptr) : data_(ptr) {
        cout << "ctor" << endl;
        count_ = data_ ? new int(1) : nullptr;
    }
    SharedPtr(const SharedPtr &s) : data_(s.data_), count_(s.count_) {
        cout << "copy ctor" << endl;
        if (count_) (*count_)++;
    }
    SharedPtr(SharedPtr &&s) : data_(s.data_), count_(s.count_) {
        cout << "move ctor" << endl;
        s.data_ = nullptr;
        s.count_ = nullptr;
    }
    ~SharedPtr() {
        cout << "dtor" << endl;
        if (count_ && --(*count_) == 0) {
            delete data_;
            data_ = nullptr;
            delete count_;
            count_ = nullptr; 
        }
    }
    SharedPtr<T> &operator=(const SharedPtr &s) {
        cout << "operator=" << endl;
        // self assign
        if (data_ == s.data_) return *this;
        // ~SharedPtr()
        if (count_ && --(*count_) == 0) {
            delete data_;
            data_ = nullptr;
            delete count_;
            count_ = nullptr;
        }
        // SharedPtr(const SharedPtr &s)
        data_ = s.data_;
        count_ = s.count_;
        if (count_) (*count_)++;
        // return
        return *this;
    }
    int useCount() { return count_ ? *count_ : 0; }
private:
    int *count_;
    T *data_;
};

SharedPtr<int> test(SharedPtr<int> ptr) { // call copy ctor
    cout << "-----test in-----" << endl;
    return ptr; // if possible, call move ctor; if not, call copy ctor
}

int main() {
    SharedPtr<int> p1(new int());
    cout << "useCount: " << p1.useCount() << endl << endl;
    
    SharedPtr<int> p2(p1);
    cout << "useCount: " << p1.useCount() << " " << p2.useCount() << endl << endl;
    
    SharedPtr<int> p3(std::move(p2));
    cout << "useCount: " << p1.useCount() << " " << p2.useCount() << endl << endl;

    p2 = p1;
    cout << "useCount: " << p1.useCount() << " " << p2.useCount() << endl << endl;

    cout << "-----test begin-----" << endl;
    test(p1);
    cout << "-----test end-----" << endl;
    return 0;
}
