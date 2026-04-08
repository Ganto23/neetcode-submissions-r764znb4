class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int n = s.size();
        std::bitset<128> seen;
        int longest = 0;

        for (int r = 0; r < n; ++r) {
            while (seen.test(s[r])) {
                seen.reset(s[l]);
                l++;
            }
            
            seen.set(s[r]);
            longest = std::max(longest, r-l+1);
            
        }
        return longest;
    }
};
