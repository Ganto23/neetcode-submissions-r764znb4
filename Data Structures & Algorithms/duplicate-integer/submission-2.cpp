class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> no_dupes(nums.begin(),nums.end());
        if (no_dupes.size() == nums.size()){
            return false;
        }
        return true;
    }
};