#include <vector>
#include <string>
using namespace std;

int main() {
    // ptr
    vector<string*> string_ptrs;
    string foo = "foo";
    string bar = "bar";
    string_ptrs.push_back(&foo);
    string_ptrs.push_back(&bar);

    // ref
    vector<string&> string_refs; // compile error
    // elements in vector must support operator= and copy ctor
    // but ref don't support operator=
    return 0;
}