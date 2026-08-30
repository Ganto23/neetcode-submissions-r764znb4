class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> counts(26,0);
        for (char c : s) {
            counts[c - 'a']++;
        }
        for (char c : t) {
            counts[c - 'a']--;
        }
        for (int count : counts) {
            if (count != 0) return false;
        }
        return true;
    }
};
