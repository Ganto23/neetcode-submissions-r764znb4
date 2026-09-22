class Solution {
public:

    int solve(vector<int>& nums, int i, int cur, int target) {
        if(i == nums.size()) return cur == target;
        return solve(nums, i+1, cur-nums[i], target) + solve(nums, i+1, cur+nums[i], target);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        int n = nums.size();
        vector<vector<int>> dp(nums.size(), vector<int>(2*total+1, -1));

        // for(int i=n-1; i>=0; --i) {
        //     for(int j=total; j>=0; --j) {
        //         dp[i][j] = dp[i+1][]
        //     }
        // }
        function<int(int,int)> recur = [&](int cur, int idx) -> int {
            if(idx == nums.size()) return cur == target;
            int& m = dp[idx][cur+total];
            if (m != -1) return m;
            return m = recur(cur-nums[idx], idx+1) + recur(cur+nums[idx], idx+1);
        };

        return recur(0,0);
    }
};
