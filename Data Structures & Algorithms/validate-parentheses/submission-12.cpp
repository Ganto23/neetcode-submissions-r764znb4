class Solution {
public:
    bool isValid(string s) {
        std::vector<char> stack;
        int stack_len = 0;
        std::unordered_map<char,char> dict;
        dict[')'] = '(';
        dict['}'] = '{';
        dict[']'] = '[';
        
        if (s[0]==')' || s[0]=='}' || s[0]==']' || s.size() < 2){
            return false;
        }

        for (char c: s){
            if (c == '(' || c=='{' || c=='['){
                stack.push_back(c);
                stack_len++;
            } else if (dict[c] == stack[stack_len-1]){
                stack.pop_back();
                stack_len--;
            } else {
                return false;
            }
        }
        if (stack.size() > 0){
            return false;
        }
        return true;
    }
};
