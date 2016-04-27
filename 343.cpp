// 343. Integer Break

class Solution {
public: // http://www.cnblogs.com/grandyang/p/5411919.html
    int integerBreak(int n) {
        if (n==2 ||n==3) return n-1;
        int res = 1;
        while (n>4) {
            res *= 3;
            n -= 3;
        }
        return n*res;
    }
};


class Solution {
public: // DP
    int integerBreak(int n) {
        vector<int> dp{0, 0, 1, 2, 4, 6, 9};
        for (int i=7; i<=n; i++) dp.push_back(dp[i-3]*3);
        return dp[n]; // dp.back() is wrong since n maybe < 7
    }
};