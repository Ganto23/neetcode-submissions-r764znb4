class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int matches = 26;
        int freq[26] = {0};

        for (char c : s1) {
            freq[c - 'a']++;
        }

        for (int i : freq) {
            if (i != 0) {
                matches--;
            }
        }
        std::cout << "Starting matches: " << matches << std::endl;

        int l = 0;
        int r = 0;

        while (r < s1.size()) {
            if (freq[s2[r] - 'a'] == 0) {
                matches--;
            } else if (freq[s2[r] - 'a'] == 1) {
                matches++;
            }
            freq[s2[r] - 'a']--;
            r++;
        }
        if (matches == 26) {
            return true;
        }
        std::cout << "R: " << r << ", matches: " << matches << std::endl;

        while (r < s2.size()) {
            if (freq[s2[r] - 'a'] == 0) {
                matches--;
            } else if (freq[s2[r] - 'a'] == 1) {
                matches++;
            }
            freq[s2[r] - 'a']--;
            r++;

            if (freq[s2[l] - 'a'] == 0) {
                matches--;
            } else if (freq[s2[l] - 'a'] == -1) {
                matches++;
            }
            freq[s2[l] - 'a']++;
            l++;

            std::cout << "R: " << r << ", L: " << l << ", Matches: " << matches << std::endl;

            if (matches == 26) return true;
        }
        return false;
    }
};
