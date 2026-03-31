class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;
        
        while (l <= r){
            if (!(isalpha(s[l]) || isdigit(s[l]))){
                l++;
                continue;
            } else if (!(isalpha(s[r]) || isdigit(s[r]))){
                r--;
                continue;
            }
            if (tolower(s[l]) != tolower(s[r])){
                cout << s[l] << s[r] << l << r;
                return false;
            }
            l++;
            r--;
        }
        return true;
        
    }
};
