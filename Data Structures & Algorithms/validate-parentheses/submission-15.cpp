class Solution {
public:
    bool isValid(string s) {
        std::vector<char> m_stack;
        m_stack.reserve(s.size());
        char pairs[128] = {0};
        pairs[']'] = '[';
        pairs['}'] = '{';
        pairs[')'] = '(';

        for (char c : s) {
            if (c == '[' || c == '{' || c == '(') {
                m_stack.push_back(c);
                continue;
            }

            if (!m_stack.empty() && m_stack.back() == pairs[c]){
                m_stack.pop_back();
            } else {
                return false;
            }
            
        }
        return m_stack.empty();
    }
};
