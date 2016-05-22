// 304. Range Sum Query 2D - Immutable

class NumMatrix {
private:
    vector<vector<int>> dp;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        dp.resize(m + 1, vector<int> (n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                dp[i][j] = matrix[i - 1][j - 1] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] + dp[row1][col1] - dp[row1][col2 + 1] - dp[row2 + 1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);