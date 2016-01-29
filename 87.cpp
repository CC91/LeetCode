// 87. Scramble String

class Solution {
public:// dp[n][i][j] = (dp[k][i][j] && dp[n-k][i+k][j+k]) || (dp[k][i][j+n-k] && dp[n-k][i+k][j])
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        if (n!=s2.size()) return false;
        bool dp[n+1][n][n];
        fill_n(&dp[0][0][0], (n+1)*n*n, false);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) dp[1][i][j] = s1[i]==s2[j];
        }
        
        for (int i=1; i<=n; i++) {
            for (int j=0; i+j<=n; j++) {
                for (int p=0; p+i<=n; p++) {
                    for (int q=1; q<i; q++) {
                        if ((dp[q][j][p] && dp[i-q][j+q][p+q]) ||(dp[q][j][p+i-q] && dp[i-q][j+q][p])) {
                            dp[i][j][p] = true;
                            break;
                        }
                    }
                }
            }
        }
        return dp[n][0][0];
    }
};


class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1==s2) return true;
        int n = s1.size();
        int cnt[26] = {0};
        for (int i=0; i<n; i++) {
            cnt[s1[i]-'a']++;
            cnt[s2[i]-'a']--;
        }
        for (int i=0;i<26; i++) {
            if (cnt[i]!=0) return false;
        }
        for (int i=1; i<n; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) return true;
            if (isScramble(s1.substr(0, i), s2.substr(n-i)) && isScramble(s1.substr(i), s2.substr(0, n-i))) return true;
        }
        return false;
    }
};