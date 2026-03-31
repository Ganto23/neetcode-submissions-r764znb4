class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0){
            return 0;
        } else if (s.size() == 1){
            return 1;
        }
        int max_len = 1;
        int l = 0;
        int r = 1;

        std::unordered_map<char,int> dict;
        dict[s[0]] = 0;

        while ((l <= r) && (r < s.size())){
            if (dict.find(s[r]) != dict.end()){
                int new_l = dict[s[r]] + 1;
                for (int i = l; i < new_l; ++i){
                    dict.erase(s[i]);
                }
                l = new_l;
            } else {
                dict[s[r]] = r;
                r++;
                max_len = max(max_len, r-l);
            }
        }
        return max_len;
    }
};
