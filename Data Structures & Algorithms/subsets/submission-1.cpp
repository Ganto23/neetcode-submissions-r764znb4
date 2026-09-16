class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        out.reserve(pow(2, nums.size()));
        out.push_back({});
        backtrack(nums, 0, out);
        return out;
    }
private:
    void backtrack(vector<int>& nums, int idx, vector<vector<int>>& out) {
        if (idx >= nums.size()) return;
        for (auto sub_vec : out) {
            sub_vec.push_back(nums[idx]);
            out.push_back(sub_vec);
        }
        backtrack(nums, idx+1, out);
    }
};
