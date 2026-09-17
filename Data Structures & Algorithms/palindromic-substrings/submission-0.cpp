class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int l = i; int r = i;
            count++;
            while (l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) {
                l--;
                r++;
                count++;
            }

            if (i+1 < n && s[i] == s[i+1]) {
                count++;
                l = i; r = i+1;
                while (l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) {
                    l--;
                    r++;
                    count++;
                }
            }
        }
        return count;
    }
};
