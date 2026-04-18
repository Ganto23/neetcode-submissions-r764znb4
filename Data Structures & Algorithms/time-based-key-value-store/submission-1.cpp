class TimeMap {
    std::unordered_map<string, std::vector<std::pair<int, string>>> data;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
        std::cout << "Added: " << value << std::endl;
    }
    
    string get(string key, int timestamp) {
        int l = 0;
        int r = data[key].size();
        string ret_val = "";

        while (l < r) {
            int mid = l + (r - l)/2;
            auto cur = data[key][mid];
            if (cur.first == timestamp) {
                return cur.second;
            } else if (cur.first < timestamp) {
                ret_val = cur.second;
                l = mid + 1;
            } else {
                r = mid ;
            }
        }
        std::cout << "Got: " << ret_val << std::endl;
        return ret_val;
    }
};
