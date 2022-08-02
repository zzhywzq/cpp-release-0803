#include <iostream>
#include <climits>
using namespace std;

struct Data {
	int key;
};

class FIFO {
private:
	int _max_size;
	int _cur_size;
	Data *_datas;

public:
	FIFO(const int size) : _max_size(size), _cur_size(0), _datas(new Data[size]) {}

	~FIFO() { delete _datas; }

	bool get(int key) {
		for (int j = 0; j < _cur_size; j++) {
			if (_datas[j].key == key) {
				return true;
			}
		}
		return false;
	}

	void put(int key) {
		if (get(key)) return; // if exists, do nth
		if (_cur_size == _max_size) { // if full, replace the head one
			for (int i = 0; i < _max_size - 1; i++) {
				_datas[i] = _datas[i + 1];
			}
			_datas[_cur_size].key = key;
		}
		else {
			_datas[_cur_size].key = key;
			_cur_size++;
		}
	}
};

int main() {
	FIFO cache = FIFO(2);
	cache.put(1);
	cache.put(2);
	cout << cache.get(1) << endl;
	cache.put(3);
	cout << cache.get(2) << endl;
	return 0;
}