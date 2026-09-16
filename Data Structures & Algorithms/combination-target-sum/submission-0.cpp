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
            else if (summed == target) {
                vector<int> temp = cur_out;
                temp.push_back(nums[i]);
                out.push_back(temp);
                return;
            } else {
                vector<int> temp = cur_out;
                temp.push_back(nums[i]);
                backtrack(nums, target, out, summed, temp, i);
            }
        }
    }
};
