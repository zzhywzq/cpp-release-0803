#include <thread>
#include <iostream>
#include <queue>
#include <condition_variable>
#include <mutex>
using namespace std;

class ProducerAndConsumerDemo {
public:
	void producerNumber() {
		while (true) {
			{
				unique_lock<mutex> locker(m_mutex);
				bufferNotFull.wait(locker, [&]() { return buf.size() < maxBufferSize; }); // wait until bufferNotFull conditions established, then produce
				buf.push(data++);
				cout << "produce data: " << data << ", current bufferSize:" << buf.size() << endl;
			}
			bufferNotEmpty.notify_one();
			this_thread::sleep_for(chrono::milliseconds(1000)); // simulated produce time
		}
	}
	void consumerNumber() {
		while (true) {
			{
				unique_lock<mutex> locker(m_mutex);
				bufferNotEmpty.wait(locker, [&]() {return buf.size() > 0; }); // wait until bufferNotEmpty conditions established, then consume
				int i = buf.front(); buf.pop();
				cout << "consume data: " << i << ", current bufferSize:" << buf.size() << endl;
			}
			bufferNotFull.notify_one();
			this_thread::sleep_for(chrono::milliseconds(2000)); // simulated consume time
		}
	}
private:
	int data = 0;
	queue<int> buf;
	const int maxBufferSize = 3;
	condition_variable bufferNotEmpty;
	condition_variable bufferNotFull;
	mutex m_mutex;
};

int main() {
	ProducerAndConsumerDemo pcDemo;
	thread consumerThread(&ProducerAndConsumerDemo::producerNumber, &pcDemo);
	thread producerThread(&ProducerAndConsumerDemo::consumerNumber, &pcDemo);
	producerThread.join();
	consumerThread.join();
	return 0;
}
