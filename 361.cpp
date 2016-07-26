// 361. Bomb Enemy

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        int res = 0;
        int row = 0;
        vector<int> col(n, 0);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0 || grid[i][j - 1] == 'W') {
                    row = 0;
                    for (int k = j; k < n && grid[i][k] != 'W'; k++) {
                        if (grid[i][k] == 'E') {
                            row++;
                        }
                    }
                }
                if (i == 0 || grid[i - 1][j] =='W') {
                    col[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k++) {
                        if (grid[k][j] == 'E') {
                            col[j]++;
                        }
                    }
                }
                if (grid[i][j] == '0') {
                    res = max(res, row + col[j]);
                }
            }
        }
        return res;
    }
};