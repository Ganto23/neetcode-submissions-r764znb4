class Solution {
public:
    bool isValid(string s) {
        std::vector<char> m_stack;
        m_stack.reserve(s.size());
        std::unordered_map<char, char> m_map = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };

        for (char c : s) {
            if (c == '[' || c == '{' || c == '(') {
                m_stack.push_back(c);
                continue;
            }

            if (!m_stack.empty() && m_stack.back() == m_map[c]){
                m_stack.pop_back();
            } else {
                return false;
            }
            
        }
        return m_stack.empty();
    }
};
