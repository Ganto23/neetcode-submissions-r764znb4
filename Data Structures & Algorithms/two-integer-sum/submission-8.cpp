class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> indexed_nums;
        for(int i = 0; i < nums.size(); i++){
            indexed_nums.push_back({nums[i], i});
        }
        std::sort(indexed_nums.begin(), indexed_nums.end());

        int l = 0; int r = indexed_nums.size()-1;

        while (l < r) {
            if (indexed_nums[l].first + indexed_nums[r].first == target) {
                return {std::min(indexed_nums[l].second, indexed_nums[r].second), std::max(indexed_nums[l].second, indexed_nums[r].second)};
            } else if (indexed_nums[l].first + indexed_nums[r].first > target) {
                r--;
            } else {
                l++;
            }
        }
        return {};
    }
};
