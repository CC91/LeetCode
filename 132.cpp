// 132. Palindrome Partitioning II 

class Solution {
public: // https://leetcode.com/discuss/9476/solution-does-not-need-table-palindrome-right-uses-only-space
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1, 0);
        for (int i=0; i<=n; i++) dp[i] = i-1;
        for (int i=0; i<n; i++) {
            for (int j=0; i-j>=0 && i+j<n && s[i-j]==s[i+j]; j++) dp[i+j+1] = min(dp[i+j+1], 1+dp[i-j]); // odd length
            for (int j=1; i-j+1>=0 && i+j<n && s[i-j+1]==s[i+j]; j++) dp[i+j+1] = min(dp[i+j+1], 1+dp[i-j+1]); // even length
        }
        return dp[n];
    }
};