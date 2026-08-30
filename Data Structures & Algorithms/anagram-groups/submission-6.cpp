class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, vector<string>> mymap;
        for (const auto& str : strs) {
            string sorted = str;
            std::sort(sorted.begin(), sorted.end());
            mymap[sorted].push_back(str);
        }
        vector<vector<string>> result;
        for (const auto& [key, value] : mymap) {
            result.push_back(value);
        }
        return result;
    }
};
