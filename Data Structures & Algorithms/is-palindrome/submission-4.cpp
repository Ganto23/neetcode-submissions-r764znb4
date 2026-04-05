class Solution {
public:
    bool isPalindrome(string s) {
        static char lut[256] = {0};
        static bool initialized = false;

        if (!initialized) {
            for (int i = 0; i < 256; i++) {
                if (std::isalnum(i)) {
                    lut[i] = (char)std::tolower(i);
                } else {
                    lut[i] = 0; // Marker for "ignore this"
                }
            }
            initialized = true;
        }

        int l = 0, r = s.size() - 1;
        while (l < r) {
            char leftChar = lut[(unsigned char)s[l]];
            char rightChar = lut[(unsigned char)s[r]];

            if (leftChar == 0) { l++; continue; }
            if (rightChar == 0) { r--; continue; }
            
            if (leftChar != rightChar) return false;
            
            l++;
            r--;
        }
        return true;
    }
};
