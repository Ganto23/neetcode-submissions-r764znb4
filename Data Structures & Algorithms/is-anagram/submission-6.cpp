class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26]{};
        for (const auto& c : s) {
            count[c - 'a']++;
        }
        for (const auto& c : t) {
            count[c - 'a']--;
        }
        for (const auto& n : count){
            if (n != 0) return false;
        }
        return true;
    }
};
