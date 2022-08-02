#include<iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache { // left new, right old; erase before other operations;
public:
	LRUCache(int sz) : size_(sz) {}
	int get(int key) {
		auto iter = key_to_iter_.find(key);
		if (iter == key_to_iter_.end()) return -1;
		kv_list_.erase(iter->second);
		kv_list_.push_front(pair<int, int>(key, iter->second->second));
		key_to_iter_[key] = kv_list_.begin();
		return key_to_iter_[key]->second;
	}
	void set(int key, int value) {
		auto iter = key_to_iter_.find(key);
		if (iter == key_to_iter_.end()) {
			if (kv_list_.size() == size_) {
				key_to_iter_.erase(kv_list_.back().first);
				kv_list_.pop_back();
			}
			kv_list_.push_front(pair<int, int>(key, value));
			key_to_iter_[key] = kv_list_.begin();
		}
		else {
			kv_list_.erase(iter->second);
			kv_list_.push_front(pair<int, int>(key, value));
			key_to_iter_[key] = kv_list_.begin();
		}
	}
private:
	int size_;
	list<pair<int, int>> kv_list_;
	unordered_map<int, list<pair<int, int>>::iterator> key_to_iter_;
};

int main() {
	LRUCache lc(3);
	for (int i = 0; i < 3; ++i) lc.set(i, i);
	cout << lc.get(1) << endl;
	lc.set(4, 4);
	cout << lc.get(3) << endl;
	return 0;
}