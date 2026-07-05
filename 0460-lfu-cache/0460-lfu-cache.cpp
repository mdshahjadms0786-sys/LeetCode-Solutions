#include <unordered_map>
#include <list>
using namespace std;

class LFUCache {
private:
    int capacity;
    int minFreq;

    unordered_map<int, pair<int, int>> keyValueFreq;
    unordered_map<int, list<int>> freqList;
    unordered_map<int, list<int>::iterator> keyIterator;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyValueFreq.find(key) == keyValueFreq.end())
            return -1;

        int value = keyValueFreq[key].first;
        int freq = keyValueFreq[key].second;

        freqList[freq].erase(keyIterator[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq)
                minFreq++;
        }

        freq++;
        keyValueFreq[key].second = freq;
        freqList[freq].push_front(key);
        keyIterator[key] = freqList[freq].begin();

        return value;
    }

    void put(int key, int value) {
        if (capacity == 0)
            return;

        if (keyValueFreq.find(key) != keyValueFreq.end()) {
            keyValueFreq[key].first = value;
            get(key);
            return;
        }

        if (keyValueFreq.size() == capacity) {
            int keyToRemove = freqList[minFreq].back();
            freqList[minFreq].pop_back();

            if (freqList[minFreq].empty())
                freqList.erase(minFreq);

            keyValueFreq.erase(keyToRemove);
            keyIterator.erase(keyToRemove);
        }

        keyValueFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIterator[key] = freqList[1].begin();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */