#include <iostream>
#include <thread>
#include <string>
#include <mutex>

std::mutex mtx;

void thread_func(const std::string& msg) {
	std::unique_lock<std::mutex> guard(mtx);
	std::cout << msg << " begin" << std::endl;
	guard.unlock();

	std::cout << msg << " no lock do sth" << std::endl;

	guard.lock();
	std::cout << msg << " end" << std::endl;
	guard.unlock();
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