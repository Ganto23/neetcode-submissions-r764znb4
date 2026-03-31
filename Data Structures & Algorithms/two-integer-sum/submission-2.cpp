class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dict;
        for (int i = 0; i < nums.size();i++){
            int toFind = target - nums[i];
            if (dict.count(toFind)){
                int output = dict[toFind];
                return {output,i};
            }
            dict[nums[i]] = i;
        }
        return {0,0};
    }
};
