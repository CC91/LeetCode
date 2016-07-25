// 372. Super Pow

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int res = 1;
        for (auto n : b) {
            res = helper(res, 10) * helper(a, n) % 1337;
        }
        return res;
    }
    
    int helper(int x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x % 1337;
        }
        return helper(x % 1337, n / 2) * helper(x % 1337, n - n / 2) % 1337;
    }
};