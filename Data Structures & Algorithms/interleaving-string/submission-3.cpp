class Solution {
public:
    bool solve(string& s1, string& s2, string& s3, int i, int j, vector<vector<int>>& memo) {
        if (i >= s1.size() && j >= s2.size()) {
            return true;
        }

        if (memo[i][j] != -1) return memo[i][j];

        bool result;
        if (i >= s1.size()) {
            result = (s2[j] == s3[i+j]) ? solve(s1, s2, s3, i, j+1, memo) : false;
        } else if (j >= s2.size()) {
            result = (s1[i] == s3[i+j]) ? solve(s1, s2, s3, i+1, j, memo) : false;
        } else {
            char s3_cur = s3[i+j]; char s2_cur = s2[j]; char s1_cur = s1[i];

            if (s1_cur == s3_cur && s2_cur == s3_cur) result = solve(s1, s2, s3, i+1, j, memo) || solve(s1, s2, s3, i, j+1, memo);
            else if (s1_cur == s3_cur) result = solve(s1, s2, s3, i+1, j, memo);
            else if (s2_cur == s3_cur) result = solve(s1, s2, s3, i, j+1, memo);
            else result = false;
        }

        memo[i][j] = result;
        return result;
    }

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size()) return false;

        vector<vector<int>> memo(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return solve(s1, s2, s3, 0, 0, memo);
    }
};