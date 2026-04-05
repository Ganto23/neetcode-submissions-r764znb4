#include <array>

consteval std::array<char, 256> generate_lut() {
    std::array<char, 256> table{};
    for (int i = 0; i < 256; ++i) {
        if ((i >= 'a' && i <= 'z') || (i >= '0' && i <= '9')) {
            table[i] = (char)i;
        } else if (i >= 'A' && i <= 'Z') {
            table[i] = (char)(i + 32);
        } else {
            table[i] = 0;
        }
    }
    return table;
}

static constexpr auto lut = generate_lut();



class Solution {
public:
    bool isPalindrome(string s) {
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
