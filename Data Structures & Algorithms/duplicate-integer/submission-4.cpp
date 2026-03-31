class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> my_set;
        my_set.reserve(nums.size());
        for (const auto& n : nums) {
            auto ret_val = my_set.insert(n);
            if (!ret_val.second) return true;
        }
        return false;
    }
};