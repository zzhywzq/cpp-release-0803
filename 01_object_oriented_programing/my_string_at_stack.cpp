#include <iostream>
#include <cstring>
using namespace std;

class String {
public:
	explicit String(const char* str = "") : _size(strlen(str)) {
		strcpy(_data, str);
	}
	String(const String& s) : _size(strlen(s._data)) {
		strcpy(_data, s._data);
	}
	String(String&& s) : _size(strlen(s._data)) {
		strcpy(_data, s._data);
	}
	~String() {
		
	}
	String& operator=(const String& s) {
		// self assign
		if (&s == this) return *this;
		// ~String()

		// String(const String& s)
		_size = strlen(s._data);
		strcpy(_data, s._data);
		// return
		return *this;
	}
	bool operator==(const String& s) {
		return strcmp(s._data, _data) == 0;
	}
private:
	int _size;
	char _data[16];
};

int main() {
	String s1("");
	String s2("abc");
	String s3 = s2;
	s3 = s3;
	if (s2 == s3) cout << "echo\n";
	return 0;
}
