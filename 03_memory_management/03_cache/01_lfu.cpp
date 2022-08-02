#include <iostream>
#include <climits>
using namespace std;

struct Data {
	int key;
	int times;
};

class LFU {
private:
	int _max_size;
	int _cur_size;
	Data *_datas;

public:
	LFU(const int size) : _max_size(size), _cur_size(0), _datas(new Data[size]) {}

	~LFU() { delete _datas; }

	bool get(int key) {
		for (int j = 0; j < _cur_size; j++) {
			if (_datas[j].key == key) {
				_datas[j].times++;
				return true;
			}
		}
		return false;
	}

	void put(int key) {
		if (get(key)) return; // if exists, times++
		if (_cur_size == _max_size) { // if full, replace the min_times one
			int min_times = INT_MAX;
			int min_index = -1;
			for (int i = 0; i < _max_size; i++) {
				if (_datas[i].times < min_times) {
					min_times = _datas[i].times;
					min_index = i;
				}
			}
			_datas[min_index].key = key;
			_datas[min_index].times = 0;
		}
		else {
			_datas[_cur_size].key = key;
			_datas[_cur_size].times = 0;
			_cur_size++;
		}
	}
};

int main() {
	LFU cache = LFU(2);
	cache.put(1);
	cache.put(2);
	cout << cache.get(1) << endl;
	cache.put(3);
	cout << cache.get(2) << endl;
	return 0;
}