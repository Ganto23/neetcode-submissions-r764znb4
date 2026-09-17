class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    bool isValid(vector<vector<char>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size()) return false;
        if (j < 0 || j >= grid[0].size()) return false;
        return true;
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = '0';
                    
                    while (!q.empty()) {
                        pair<int,int> cur = q.front();
                        q.pop();

                        for (auto dir : dirs) {
                            if (isValid(grid, cur.first + dir.first, cur.second + dir.second) && grid[cur.first + dir.first][cur.second + dir.second] == '1') {
                                q.push({cur.first + dir.first, cur.second + dir.second});
                                grid[cur.first + dir.first][cur.second + dir.second] = '0';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
