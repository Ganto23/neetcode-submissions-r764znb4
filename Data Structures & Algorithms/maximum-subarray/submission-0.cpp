class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int total = 0;
        int min_pre_sum = 0;
        int m = nums[0];

        for (int num : nums) {
            total += num;
            m = max(m, total - min_pre_sum);
            min_pre_sum = min(min_pre_sum, total);
        }
        return m;
    }
};
