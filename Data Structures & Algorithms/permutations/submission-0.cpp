class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> out;
        unordered_set<int> seen;
        vector<int> cur;
        backtrack(nums, seen, out, cur);
        return out;

    }
private:
    void backtrack(vector<int>& nums, unordered_set<int>& seen, vector<vector<int>>& out, vector<int>& cur) {
        for (auto num : nums) {
            if (seen.contains(num)) continue;

            seen.insert(num);
            cur.push_back(num);
            if (cur.size() == nums.size()) {
                out.push_back(cur);
            } else {
                backtrack(nums, seen, out, cur);
            }
            cur.pop_back();
            seen.erase(num);
        }
    }
};
