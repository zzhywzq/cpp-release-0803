#include <vector> 
#include <iostream> 
using namespace std;

class testDemo {
public:
	testDemo(int num) : num_(num) {
		cout << "ctor" << endl;
	}
	testDemo(const testDemo& other) : num_(other.num_) {
		cout << "copy ctor" << endl;
	}
	testDemo(testDemo&& other) : num_(other.num_) {
		cout << "move ctor" << endl;
	}
private:
	int num_;
};

int main() {
	std::vector<testDemo> demo1;
	demo1.emplace_back(2); // don't call copy ctor or move ctor
    return 0;
}