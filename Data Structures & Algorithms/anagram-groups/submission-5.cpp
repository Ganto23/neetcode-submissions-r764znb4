class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> my_map;
        my_map.reserve(strs.size());

        for (auto str : strs) {
            std::string cpy = str;
            std::sort(str.begin(), str.end());
            my_map[str].push_back(std::move(cpy));
        }

        std::vector<std::vector<std::string>> output;
        output.reserve(my_map.size());
        for (auto& [key, group] : my_map) {
            output.push_back(std::move(group));
        }
        return output;
    }
};
