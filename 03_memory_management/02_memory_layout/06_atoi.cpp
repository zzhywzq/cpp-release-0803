#include <iostream>
using namespace std;

#define INT_MAX 2147483647

int my_atoi(const string &str) {
	long result = 0; // using long, not int, can handle test case "100000000000000000000000000"
	for (size_t i = 0; i < str.size(); ++i) {
		int temp = (str[i] - '0'); // problem simplifying: str_to_int converse to char_to_int
		if (temp > 9 || temp < 0) { return -1; }
		result = result * 10 + temp;
		if (result > INT_MAX) { return -1; }
	}
	return result;
}

int main() {
	cout << my_atoi("000") << endl;
	cout << my_atoi("100") << endl;
	cout << my_atoi("100000000000000000000000000") << endl;
	cout << my_atoi("0a") << endl;
	return 0;
}