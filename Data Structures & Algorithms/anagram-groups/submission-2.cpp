class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> my_dict;

        for (int i = 0; i < strs.size(); i++){
            string sortedString = strs[i];
            std::sort(sortedString.begin(),sortedString.end());

            my_dict[sortedString].push_back(strs[i]);

        }
        std::vector<std::vector<std::string>> result;
        for (const auto& pair : my_dict) {
            result.push_back(pair.second);
        }
        return result;
    }
};
