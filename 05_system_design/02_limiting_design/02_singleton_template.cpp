#include <iostream>
#include <memory>
#include <mutex>
using namespace std;

template <typename T>
class Singleton {
public:
	template <typename ... Args>
	static std::shared_ptr<T> GetInstance(Args&& ... args) {
		if (m_instance == nullptr) {
			std::lock_guard<std::mutex> lock(m_mutex);
			if (m_instance == nullptr) {
				m_instance = std::make_shared<T>(std::forward<Args>(args)...);
			}
		}
		return m_instance;
	}
	Singleton(const Singleton&) = delete;
	Singleton(Singleton&&) = delete;
	Singleton& operator=(const Singleton&) = delete;

protected:
	Singleton() = default;
	virtual ~Singleton() = default;

private:
	static std::shared_ptr<T> m_instance;
	static std::mutex m_mutex;
};

template <typename T>
std::shared_ptr<T> Singleton<T>::m_instance{ nullptr };

template <class T>
std::mutex Singleton<T>::m_mutex;

int main() {
	cout << Singleton<int>::GetInstance() << endl;
	cout << Singleton<double>::GetInstance() << endl;
	return 0;
}