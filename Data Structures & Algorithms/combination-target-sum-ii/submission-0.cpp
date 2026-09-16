class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> out;
        vector<int> cur;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0, cur, out);
        return out;
    }
private:
    void backtrack(vector<int>& candidates, int target, int cur_sum, int cur_idx, vector<int>& cur, vector<vector<int>>& out) {
        for (int i = cur_idx; i < candidates.size(); ++i) {
            if (i > cur_idx && candidates[i] == candidates[i - 1]) continue;
            int summed = cur_sum + candidates[i];
            if (summed > target) return;

            cur.push_back(candidates[i]);
            if (summed == target) {
                out.push_back(cur);
            } else {
                backtrack(candidates, target, summed, i+1, cur, out);
            }
            cur.pop_back();
        }
    }
};
