// 264. Ugly Number II

class Solution {
public: // dp[i] = min(2*dp(i2), 3*dp(i3), 5*dp(i5))
// http://www.cnblogs.com/grandyang/p/4743837.html find minimum multiplication result of prime factors
    int nthUglyNumber(int n) {
        if (n<=3) return n;
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> res(n);
        res[0] = 1;
        for (int i=1; i<n; i++) {
            res[i] = min(min(res[i2]*2, res[i3]*3), res[i5]*5);
            if (res[i]==res[i2]*2) i2++;
            if (res[i]==res[i3]*3) i3++;
            if (res[i]==res[i5]*5) i5++;
        }
        return res[n-1];
    }
};