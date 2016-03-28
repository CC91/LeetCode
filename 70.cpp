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


class Solution {
public:// math O(1) time and space
    int climbStairs(int n) {
        double t = sqrt(5);
        return floor((pow((1+t)/2, n+1)-pow((1-t)/2, n+1))/t); // since the sequence starts from a0
    }
};