#include <stdlib.h> 
#include <stdio.h> 
#include <time.h>
#include <iostream> 
#include <sys/time.h>
using namespace std;

string test(string s) {
	string result;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] >= 0x20) result = result + s[i];
	return result;
}

inline string test2(string s) { // inline
	string result;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] >= 0x20) result = result + s[i];
	return result;
}

string test3(string s) { // reserve
	string result;
    result.reserve(s.length());
	for (int i = 0; i < s.length(); ++i)
		if (s[i] >= 0x20) result = result + s[i];
	return result;
}

string test4(string& s) { // &
	string result;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] >= 0x20) result = result + s[i];
	return result;
}

string test5(string s) { // += avoid copy
	string result;
	for (int i = 0; i < s.length(); ++i)
		if (s[i] >= 0x20) result += s[i];
	return result;
}

int main() {
	string str = "klhnjuijhsbdcfg@ldkmqaaaohasfiush";
	struct timeval start, end;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000; ++i) test(str);
	gettimeofday(&end, NULL);
	uint64_t time1 = (end.tv_sec - start.tv_sec) * 1000 * 1000 + end.tv_usec - start.tv_usec;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000; ++i) test2(str);
	gettimeofday(&end, NULL);
	uint64_t time2 = (end.tv_sec - start.tv_sec) * 1000 * 1000 + end.tv_usec - start.tv_usec;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000; ++i) test3(str);
	gettimeofday(&end, NULL);
	uint64_t time3 = (end.tv_sec - start.tv_sec) * 1000 * 1000 + end.tv_usec - start.tv_usec;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000; ++i) test4(str);
	gettimeofday(&end, NULL);
	uint64_t time4 = (end.tv_sec - start.tv_sec) * 1000 * 1000 + end.tv_usec - start.tv_usec;

	gettimeofday(&start, NULL);
	for (int i = 0; i < 100000; ++i) test5(str);
	gettimeofday(&end, NULL);
	uint64_t time5 = (end.tv_sec - start.tv_sec) * 1000 * 1000 + end.tv_usec - start.tv_usec;

	cout << "time1 is: " << time1 << " time2 is: " << time2 << endl;
	cout << "time1 is: " << time1 << " time3 is: " << time3 << endl;
    cout << "time1 is: " << time1 << " time4 is: " << time4 << endl;
    cout << "time1 is: " << time1 << " time5 is: " << time5 << endl;
	return 0;
}