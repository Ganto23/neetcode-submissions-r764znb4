class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(std::remove_if (s.begin(), s.end(), [](unsigned char c) { return !std::isalnum(c);}), s.end());

        int n = s.size() / 2;
        auto start_it = s.begin();
        auto end_it = s.rbegin();

        for (int i = 0; i < n; ++i) {
            if (std::tolower(*start_it) != std::tolower(*end_it)) return false;
            start_it++;
            end_it++;
        }
        return true;
    }
};
