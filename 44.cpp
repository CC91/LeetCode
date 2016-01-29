// 44. Wildcard Matching

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1, false));
        dp[0][0] = true;
        for (int i=0; i<=m; i++) {
            for (int j=1; j<=n; j++) {
                if (p[j-1]==s[i-1] || p[j-1]=='?') dp[i][j] = i>0 && dp[i-1][j-1];
                else if (p[j-1]=='*') dp[i][j] = dp[i][j-1] || (i>0 && (dp[i-1][j-1] || dp[i-1][j])); // match 0/1/more elements
            }
        }
        return dp[m][n];
    }
};


class Solution {
public: // http://simpleandstupid.com/2014/10/26/wildcard-matching-leetcode-%E8%A7%A3%E9%A2%98%E7%AC%94%E8%AE%B0/
    bool isMatch(string s, string p) {
        int i = 0, j = 0, star = -1, mark = -1, m = s.size(), n = p.size();
        while (i<m) {
            if (j<n && (p[j]=='?' ||p[j]==s[i])) {
                i++;
                j++;
                continue;
            } else if (j<n && p[j]=='*') {
                star = j;
                j++;
                mark = i;
            } else if (star!=-1) {
                j = star+1;
                i = mark++;
            } else return false;
        }
        while (j<n && p[j]=='*') j++;
        return j==n;
    }
};