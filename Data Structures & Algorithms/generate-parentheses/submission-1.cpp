class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string cur = "";
        backtrack(n, out, cur, 0, 0);
        return out;
    }
private:
    void backtrack(int n, vector<string>& out, string cur, int open, int closed) {
        if (cur.size() == 2*n) {
            out.push_back(cur);
            return;
        }

        if (open == 0) {
            cur += '(';
            backtrack(n, out, cur, open+1, closed);
        } else if (closed + open < n) {
            cur += '(';
            backtrack(n, out, cur, open+1, closed);
            cur.pop_back();

            cur += ')';
            backtrack(n, out, cur, open-1, closed+1);
        } else {
            cur += ')';
            backtrack(n, out, cur, open-1, closed+1);
        }
    }
};
