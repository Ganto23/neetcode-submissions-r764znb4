class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string cur = "";
        vector<char> st;
        backtrack(n, out, cur, st, 0);
        return out;
    }
private:
    void backtrack(int n, vector<string>& out, string cur, vector<char> st, int closed) {
        if (cur.size() == 2*n) {
            out.push_back(cur);
            return;
        }

        if (st.empty()) {
            cur += '(';
            st.push_back('(');
            backtrack(n, out, cur, st, closed);
        } else if (closed + st.size() < n) {
            cur += '(';
            st.push_back('(');
            backtrack(n, out, cur, st, closed);
            st.pop_back();
            cur.pop_back();

            st.pop_back();
            cur += ')';
            backtrack(n, out, cur, st, closed+1);
        } else {
            st.pop_back();
            cur += ')';
            backtrack(n, out, cur, st, closed+1);
        }
    }
};
