class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> my_map;
        my_map.reserve(strs.size());

        for (auto str : strs) {
            std::string cpy = str;
            std::sort(str.begin(), str.end());
            if (my_map.contains(str)){
                my_map[str].push_back(cpy);
            } else {
                my_map[str] = {cpy};
            }
        }

        std::vector<std::vector<std::string>> output;
        for (auto it = my_map.begin(); it != my_map.end(); it++) {
            output.push_back(it->second);
        }
        return output;
    }
};
