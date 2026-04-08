class Solution {
public:
    int characterReplacement(string s, int k) {
        int freq[26] = {0};
        int max_freq = 0;
        int l = 0;
        int n = s.size();

        for (int r = 0; r < n; ++r) {
            max_freq = std::max(max_freq, ++freq[s[r] - 'A']);

            if ((r - l + 1) - max_freq > k) {
                freq[s[l] - 'A']--;
                l++;
            }
        }
        return n - l;
    }
};