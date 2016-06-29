// 146. LRU Cache

class LRUCache{
public:
    LRUCache(int capacity) {
        N = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }
        l.splice(l.begin(), l, it -> second);
        return it -> second -> second;
    }
    
    void set(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            l.erase(it -> second);
        }
        l.push_front({key, value});
        m[key] = l.begin();
        if (m.size() > N) {
            int k = l.rbegin() -> first;
            l.pop_back();
            m.erase(k);
        }
    }
    
private:
    int N;
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> m;

};