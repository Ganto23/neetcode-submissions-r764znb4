class LRUCache {
public:
    LRUCache(int capacity) : _capacity(capacity) {}

    int get(int key) {
        auto it = _map.find(key);
        if (it == _map.end()) return -1;
        _list.splice(_list.end(), _list, it->second); // move to back, O(1), no realloc
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = _map.find(key);
        if (it != _map.end()) {
            it->second->second = value;
            _list.splice(_list.end(), _list, it->second);
            return;
        }
        _list.push_back({key, value});
        _map[key] = std::prev(_list.end());
        if (_map.size() > _capacity) {
            _map.erase(_list.front().first);
            _list.pop_front();
        }
    }

private:
    std::list<std::pair<int,int>> _list;
    std::unordered_map<int, std::list<std::pair<int,int>>::iterator> _map;
    int _capacity;
};