class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        out.reserve(1 << nums.size());
        out.push_back({});
        backtrack(nums, 0, out);
        return out;
    }
private:
    void backtrack(vector<int>& nums, int idx, vector<vector<int>>& out) {
        if (idx >= nums.size()) return;
        size_t n = out.size();
        for (size_t i = 0; i < n; ++i) {
            vector<int> sub_vec(out[i]);
            sub_vec.push_back(nums[idx]);
            out.push_back(move(sub_vec));
        }
        backtrack(nums, idx+1, out);
    }
};

