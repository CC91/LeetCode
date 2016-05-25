// 200. Number of Islands

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int res = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    res++;
                    helper(grid, i, j);
                }
            }
        }
        return res;
    }
    
    void helper(vector<vector<char>>& grid, int i, int j) {
        grid[i][j] = '*';
        int m = grid.size();
        int n = grid[0].size();
        if (i - 1 >= 0 && grid[i - 1][j] == '1') {
            helper(grid, i - 1, j);
        }
        if (i + 1 < m && grid[i + 1][j] == '1') {
            helper(grid, i + 1, j);
        }
        if (j - 1 >= 0 && grid[i][j - 1] == '1') {
            helper(grid, i, j - 1);
        }
        if (j + 1 < n && grid[i][j + 1] == '1') {
            helper(grid, i, j + 1);
        }
    }
};