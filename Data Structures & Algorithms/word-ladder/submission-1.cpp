class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, vector<string>> adj;
        int a = beginWord.size()-1;
        int n = wordList.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int match = 0;
                for (int k = 0; k < beginWord.size(); ++k) {
                    if (wordList[i][k] == wordList[j][k]) match++;
                } 
                if (match == a) {
                    adj[wordList[i]].push_back(wordList[j]);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            int match = 0;
            for (int k = 0; k < beginWord.size(); ++k) {
                if (beginWord[k] == wordList[i][k]) match++;
            }
            if (match == a) adj[beginWord].push_back(wordList[i]);
        }

        unordered_set<string> seen;
        queue<string> q;
        int tick = 2;
        q.push(beginWord);

        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                string cur = q.front();
                q.pop();
                for (auto& vec : adj[cur]) {
                    if (seen.contains(vec)) continue;
                    if (vec == endWord) return tick;
                    q.push(vec);
                    seen.insert(vec);
                }
            }
            tick++;
        }
        return 0;
    }
};
