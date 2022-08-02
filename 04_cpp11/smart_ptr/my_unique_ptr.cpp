#include <iostream>
using namespace std;

template<typename T>
class UniquePtr {
public:
    explicit UniquePtr(T *p = nullptr) : data_(p) { cout << "ctor" << endl; }
    UniquePtr(const UniquePtr &p) = delete;
    UniquePtr(UniquePtr &&p) : data_(p.data_) {
        cout << "move ctor" << endl;
        p.data_ = nullptr;
    }
    ~UniquePtr() {
        cout << "dtor" << endl;
        if (data_) {
            delete data_;
            data_ = nullptr;
        }
    }
    UniquePtr &operator=(const UniquePtr &p) = delete;
private:
    T *data_;
};

int main() {
    UniquePtr<int> p1(new int());
    UniquePtr<int> p2(std::move(p1));
    return 0;
}