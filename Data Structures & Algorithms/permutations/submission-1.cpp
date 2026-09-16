class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        vector<bool> used(nums.size(), false);
        vector<int> cur;
        backtrack(nums, used, out, cur);
        return out;
    }
private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<vector<int>>& out, vector<int>& cur) {
        if (cur.size() == nums.size()) {
            out.push_back(cur);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            cur.push_back(nums[i]);
            backtrack(nums, used, out, cur);
            cur.pop_back();
            used[i] = false;
        }
    }
};