class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> hashset;
        for (int i = 0; i < nums.size(); ++i) {
            if (hashset.contains(nums[i])) {
                return true;
            } else {
                hashset.insert(nums[i]);
            }
        }
        return false;
    }
};