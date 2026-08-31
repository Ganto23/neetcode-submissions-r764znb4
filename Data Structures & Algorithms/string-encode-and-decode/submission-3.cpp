class Solution {
public:

    string encode(vector<string>& strs) {
        string out;
        for (const auto& str : strs) {
            out += to_string(str.size());
            out += '#';
            out += str;
        }
        return out;
    }

    vector<string> decode(string s) {
        vector<string> out;
        int i = 0;
        while (i < s.size()) {
            size_t hashPos = s.find('#', i);
            int len = std::stoi(s.substr(i, hashPos - i));
            string str = s.substr(hashPos + 1, len);
            out.push_back(str);
            i = hashPos + 1 + len;
        }
        return out;
    }
};
