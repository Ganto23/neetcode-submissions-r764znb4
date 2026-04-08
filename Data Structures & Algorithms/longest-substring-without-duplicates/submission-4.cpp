class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last_seen[128] = {0}; 
        int max_len = 0;
        int l = 0;

        for (int r = 0; r < s.size(); ++r) {
            unsigned char c = s[r];
            l = std::max(l, last_seen[c]);
            
            max_len = std::max(max_len, r - l + 1);
            last_seen[c] = r + 1;
        }
        return max_len;
    }
};
