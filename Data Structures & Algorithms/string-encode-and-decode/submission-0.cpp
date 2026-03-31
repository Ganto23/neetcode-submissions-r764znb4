#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encoded_string;
        for (const string& s : strs) {
            encoded_string += to_string(s.length()) + '#' + s;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_strings;
        int i = 0;
        while (i < s.length()) {
            int j = i;
            while (j < s.length() && s[j] != '#') {
                j++;
            }
            int length = stoi(s.substr(i, j - i));
            decoded_strings.push_back(s.substr(j + 1, length));
            i = j + 1 + length;
        }
        return decoded_strings;
    }
};