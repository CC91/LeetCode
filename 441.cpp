// 441. Arranging Coins

class Solution {
public:
    int arrangeCoins(int n) {
        if (!n) {
            return 0;
        }
        int res = 0;
        int base = 1;
        while (n >= base) {
            n -= base;
            res++;
            base++;
        }
        return res;
    }
};


class Solution {
public:
    int arrangeCoins(int n) {
        if (!n) {
            return 0;
        }
        return (sqrt(1 + 8 * (long)n) - 1) / 2;
    }
};


class Solution {
public:
    int arrangeCoins(int n) {
        if (!n) {
            return 0;
        }
        long ln = (long) n;
        long left = 1;
        long right = ln;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid * mid + mid <= 2 * ln) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left - 1;
    }
};