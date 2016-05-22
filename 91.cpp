// 91. Decode Ways

class Solution {
public:
    int numDecodings(string s) {
        if (s.empty() || s[0] == '0') {
            return 0;
        }
        int n = s.size();
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0') dp[i + 1] += dp[i];
            int val = (s[i - 1] - '0') * 10 + (s[i] - '0');
            if (val > 9 && val <= 26) {
                dp[i + 1] += dp[i - 1];
            }
        }
        return dp[n];
    }
};