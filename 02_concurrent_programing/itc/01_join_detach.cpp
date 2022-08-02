#include <iostream>
#include <thread>
#include <thread>
#include <chrono>

void test_join() {
	std::thread t1([=]() {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "t1 do sth\n";
	});
	t1.join(); // diff: join() will block here
	std::cout << std::to_string(t1.joinable()) + "\n"; // same: join() sets joinable false 
}

void test_detach() {
	std::thread t2([=]() {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "t2 do sth\n";
	});
	t2.detach(); // diff: detach() will not block here
	std::cout << std::to_string(t2.joinable()) + "\n";  // same: detach() sets joinable false 
}

int main() {
	test_join();
	std::cout << std::endl;
	test_detach();
	std::this_thread::sleep_for(std::chrono::seconds(2));
	return 0;
}