class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int max_len = 0;
        string longest = "";
        for (int i = 0; i < n; ++i) {
            int l = i; int r = i;
            while (l >= 0 && s[l] == s[i]) {
                l--;
            }
            l++;
            while (r < n && s[r] == s[i]) {
                r++;
            }
            r--;

            while (r+1 < n && l-1 >= 0 && s[r+1] == s[l-1]) {
                r++;
                l--;
            }

            int len = r - l + 1;
            if (len > max_len) {
                max_len = len;
                longest = s.substr(l, len);
            }
        }
        return longest;
    }
};
