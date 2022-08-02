#include <iostream>
#include <cstring>
using namespace std;

class String {
public:
	explicit String(const char* str = "") : _size(strlen(str)), _data(new char[_size + 1]) {
		strcpy(_data, str);
	}
	String(const String& s) : _size(strlen(s._data)), _data(new char[_size + 1]) {
		strcpy(_data, s._data);
	}
	String(String&& s) : _size(strlen(s._data)), _data(s._data) {
		s._data = nullptr;
	}
	~String() {
		if (_data != nullptr) {
			delete[] _data;
			_data = nullptr;
		}
	}
	String& operator=(const String& s) {
		// self assign
		if (&s == this) return *this;
		// ~String()
		if (_data != nullptr) {
			delete[] _data;
			_data = nullptr;
		}
		// String(const String& s)
		_size = strlen(s._data);
		_data = new char[_size + 1];
		strcpy(_data, s._data);
		// return
		return *this;
	}
	bool operator==(const String& s) {
		return strcmp(s._data, _data) == 0;
	}
private:
	int _size;
	char* _data;
};

int main() {
	String s1("");
	String s2("abc");
	String s3 = s2; // lvalue not inited => call copy constructor
	s3 = s3; // lvalue inited => call operator= : operator= will delete _data, so init is needed
	if (s2 == s3) cout << "echo\n";
	return 0;
}
