class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> mymap;
        for (int i = 0; i < nums.size(); ++i) {
            if (mymap.contains(target - nums[i])) {
                return {mymap[target-nums[i]], i};
            } else {
                mymap[nums[i]] = i;
            }
        }
        return {};
    }
};
