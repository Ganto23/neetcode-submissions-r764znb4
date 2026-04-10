class Solution {
public:
    string minWindow(string s, string t) {
        int freq[64] = {0};
        int matches = 52;
        int min_window = std::numeric_limits<int>::max();
        std::string smallest_string;

        for (char c : t) {
            freq[c - 'A']++;
        }
        for (int i : freq) {
            if (i != 0) matches--;
        }

        int l = 0;
        for (int r = 0; r < s.size(); ++r) {
            freq[s[r] - 'A']--;
            if (freq[s[r] - 'A'] == 0) {
                matches++;
                if (matches == 52) {
                    if (min_window > r-l+1){
                        smallest_string = s.substr(l, r-l+1);
                        min_window = r-l+1;
                    }
                }
            }
            while (l < r && freq[s[l] - 'A'] < 0) {
                freq[s[l] - 'A']++;
                //if (freq[s[l] - 'A'] > 0) matches--;
                l++;
                if (matches == 52) {
                    if (min_window > r-l+1){
                        smallest_string = s.substr(l, r-l+1);
                        min_window = r-l+1;
                    }
                }
            }
            
            std::cout << matches << std::endl;
        }
        return smallest_string;
    }
};
