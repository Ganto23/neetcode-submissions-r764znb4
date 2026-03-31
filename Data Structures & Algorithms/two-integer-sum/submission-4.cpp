class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> my_map;

        for (int i = 0; i < nums.size(); ++i) {
            if (auto it = my_map.find(target - nums[i]); it != my_map.end()) {
                return {it->second, i};
            } else {
                my_map[nums[i]] = i;
            }
        }
        return {0,0};
    }
};
