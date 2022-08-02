#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex mtx;

void thread_func(const std::string& msg) {
	std::lock_guard<std::mutex> guard(mtx);
	std::cout << msg << " do sth" << std::endl;
}

void test() {
	std::thread t1([&]() {
		for (int i = 0; i < 100; ++i) {
			thread_func("t1");
		}
	});
	std::thread t2([&]() {
		for (int i = 0; i < 100; ++i) {
			thread_func("t2");
		}
	});
	t1.join();
	t2.join();
}

int main() {
	test();
	return 0;
}