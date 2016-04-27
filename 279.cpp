// 279. Perfect Squares 

class Solution {
public:// http://www.cnblogs.com/grandyang/p/4800552.html
    int numSquares(int n) {
        while (n%4==0) n /= 4;
        if (n%8==7) return 4;
        for (int a=0; a*a<=n; a++) {
            int b = sqrt(n-a*a);
            if (a*a+b*b==n) return !!a+!!b; // negation, also called logical complement
        }
        return 3;
    }
};


class Solution {
public: // DP
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for (int i=0; i<=n; i++) {
            for (int j=1; j*j+i<=n; j++) dp[i+j*j] = min(dp[i+j*j], dp[i]+1);
        }
        return dp.back(); // dp[n]
    }
};