// 70. Climbing Stairs

class Solution {
public: // dp: f(n) = f(n-1)+f(n-2), need 2 previous variables only
    int climbStairs(int n) {
        if (n<3) return n;
        int f1 = 1, f2 = 2;
        for (int i=3; i<=n; i++) {
            f2 += f1;
            f1 = f2-f1;
        }
        return f2;
    }
};