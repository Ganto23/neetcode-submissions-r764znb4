class Solution {
public:

    bool hasDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto i1 = std::adjacent_find(nums.begin(), nums.end());
        if (i1 == nums.end()) {
            return false;
        } else {
            return true;
        }
    }
};