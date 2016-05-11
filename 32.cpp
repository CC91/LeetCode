// 32. Longest Valid Parentheses 

class Solution {
public: // stack
    int longestValidParentheses(string s) {
        int res = 0;
        stack<int> stk; // store potential invalid indices
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ')' && !stk.empty() && s[stk.top()] == '(') {
                stk.pop();
                if (stk.empty()) {
                    res = i + 1;
                } else {
                    res = max(res, i - stk.top());
                }
            } else {
                stk.push(i);
            }
        }
        return res;
    }
};


class Solution {
public: // DP
    int longestValidParentheses(string s) {
        int res = 0;
        int n = s.size();
        vector<int> dp(n, 0);
        for (int i = n-2; i >= 0; i--) {
            if (s[i] == ')') {
                dp[i] = 0;
            } else {
                int j = i + dp[i+1] + 1;
                if (j < n && s[j] == ')') {
                    dp[i] = dp[i+1] + 2;
                    if (j + 1 < n) {
                        dp[i] += dp[j+1];
                    }
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};
