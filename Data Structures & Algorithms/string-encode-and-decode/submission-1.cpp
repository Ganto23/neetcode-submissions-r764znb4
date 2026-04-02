class Solution {
public:

    string encode(vector<string>& strs) {
        stringstream ss;
        for (const auto& str : strs) {
            ss << str.size() << "#" << str;
        }
        return ss.str();
    }

    vector<string> decode(string s) {
        vector<string> output;
        stringstream ss(s);
        string len_str;
        
        while (getline(ss, len_str, '#')){
            int len = stoi(len_str);
            string word(len, ' ');
            ss.read(&word[0], len);
            output.push_back(std::move(word));
        }
        return output;
    }
};
