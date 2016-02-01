// 115. Distinct Subsequences

class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1));
        dp[0][0] = 1;
        for (int i=1; i<=t.size(); i++) dp[0][i] = 0; // s is empty
        for (int i=1; i<=s.size(); i++) dp[i][0] = 1; // t is empty
        for (int i=1; i<=s.size(); i++) {
            for (int j=1; j<=t.size(); j++) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1]==t[j-1]) dp[i][j] += dp[i-1][j-1];
            }
        }
        return dp[s.size()][t.size()];
    }
};


class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> dp(t.size(), 0);
        for (int i=0; i<s.size(); i++) {
            for (int j=t.size()-1; j>=0; j--) {
                if (s[i]==t[j]) dp[j]+=(j!=0?dp[j-1]:1);
            }
        }
        return dp.back();
    }
};