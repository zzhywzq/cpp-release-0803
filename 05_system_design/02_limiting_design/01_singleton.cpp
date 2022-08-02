#include <iostream>
using namespace std;

class CSingleton
{
public:
	static CSingleton * GetInstance() {
		static CSingleton instance;
		return &instance;
	}
	CSingleton(const CSingleton& m) = delete;
	CSingleton(CSingleton&& m) = delete;
	CSingleton& operator=(const CSingleton& m) = delete;
private:
	CSingleton() {
		cout << "ctor" << endl;
	}
	~CSingleton() {
		cout << "dtor" << endl;
	}
};

int main() {
	CSingleton::GetInstance();
	return 0;
}