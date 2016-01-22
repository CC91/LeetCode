// 329. Longest Increasing Path in a Matrix

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<vector<int>> dp(m, vector<int> (n, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                res = max(res, dfs(i, j, m, n, matrix, dp));
            }
        }
        return res;
    }
    
    int dfs(int x, int y, int m, int n, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        if (dp[x][y]) return dp[x][y];
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i=0; i<4; i++) {
            int nx = x+dx[i], ny = y+dy[i];
            if (nx>=0 && nx<m && ny>=0 && ny<n && matrix[nx][ny]>matrix[x][y]) {
                dp[x][y] = max(dp[x][y], dfs(nx, ny, m, n, matrix, dp));
            }
        }
        return ++dp[x][y];
    }
};


