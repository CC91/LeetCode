// 63. Unique Paths II

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() ||obstacleGrid[0].empty() ||obstacleGrid[0][0]) return 0;
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> dp(n, 1);
        for (int i=1; i<n; i++) {  // initialization, only consider the column obstacles
            if (obstacleGrid[0][i]) dp[i] = 0;
            else dp[i] = dp[i-1];
        }
        for (int i=1; i<m; i++) {
            dp[0] = obstacleGrid[i][0]?0:dp[0]; // check the row obstacles since it is 1D dp array
            for (int j=1; j<n; j++) dp[j] = obstacleGrid[i][j]?0:dp[j]+dp[j-1];
        }
        return dp[n-1];
    }
};