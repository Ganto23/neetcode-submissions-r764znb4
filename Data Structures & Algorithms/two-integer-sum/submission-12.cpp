class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<std::pair<int, int>> indexed_nums;
        indexed_nums.reserve(nums.size());
        for(int i = 0; i < nums.size(); i++){
            indexed_nums.emplace_back(nums[i], i);
        }
        std::sort(indexed_nums.begin(), indexed_nums.end());

        int l = 0; int r = indexed_nums.size()-1;

        while (l < r) {
            const auto& in_l = indexed_nums[l]; const auto& in_r = indexed_nums[r];
            int current_sum = in_l.first + in_r.first;
            if (current_sum == target) {
                if (in_l.second > in_r.second) {
                    return {in_r.second, in_l.second};
                } else {
                    return {in_l.second, in_r.second};
                } 
            } else if (current_sum > target) {
                r--;
            } else {
                l++;
            }
        }
        return {};
    }
};
