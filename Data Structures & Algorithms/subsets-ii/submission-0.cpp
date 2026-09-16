class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> out; out.push_back({});
        sort(nums.begin(), nums.end());
        backtrack(nums, out, 0, 0);
        return out;
    }
private:
    void backtrack(vector<int>& nums, vector<vector<int>>& out, int cur_idx, int prev_start) {
        if (cur_idx >= nums.size()) return;
        int n = out.size();
        int start = (cur_idx > 0 && nums[cur_idx] == nums[cur_idx - 1]) ? prev_start : 0;
        for (int i = start; i < n; ++i) {
            vector<int> cur(out[i]);
            cur.push_back(nums[cur_idx]);
            out.push_back(cur);
        } 
        backtrack(nums, out, cur_idx+1, n);
    }
};
