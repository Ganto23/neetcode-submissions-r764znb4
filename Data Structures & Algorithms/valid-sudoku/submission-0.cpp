class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; ++i) {
            std::unordered_set<char> cache1;
            std::unordered_set<char> cache2; 
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && !cache1.insert(board[i][j]).second) {
                    return false;
                }
                if (board[j][i] != '.' && !cache2.insert(board[j][i]).second) return false;
            }
        }

        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                std::unordered_set<char> cache;
                for (int x = 0; x < 3; ++x) {
                    for (int y = 0; y < 3; ++y) {
                        if (board[3*i + x][3*j + y] != '.' && !cache.insert(board[3*i + x][3*j + y]).second) return false;
                    }
                }
            }
        }

        return true;
    }
};
