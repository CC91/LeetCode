// 62. Unique Paths

class Solution {
public: // http://bangbingsyb.blogspot.com/2014/11/leetcode-unique-paths-i-ii.html
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) dp[j] += dp[j-1];
        }
        return dp[n-1];
    }
};