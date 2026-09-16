class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        backtrack(nums, target, out, 0, {}, 0);
        return out;
    }
private:
    void backtrack(vector<int>& nums, int target, vector<vector<int>>& out, int cur_sum, vector<int> cur_out, int cur_idx) {
        for (int i = cur_idx; i < nums.size(); ++i) {
            int summed = cur_sum + nums[i];
            if (summed > target) return;
            cur_out.push_back(nums[i]);
            if (summed == target) {
                out.push_back(cur_out);
                return;
            } else {
                backtrack(nums, target, out, summed, cur_out, i);
            }
            cur_out.pop_back();
        }
    }
};
