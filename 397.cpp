// 397. Integer Replacement

class Solution {
public:
    int integerReplacement(int n) {
        if (n == 1) {
            return 0;
        }
        if (n % 2 == 0) {
            return 1 + integerReplacement(n / 2);
        } else {
            long t = n;
            return 2 + min(integerReplacement((t + 1) / 2), 
                integerReplacement((t - 1) / 2));
        }
    }
};


class Solution {
public:
    int integerReplacement(int n) {
        if (n == INT_MAX) {
            return 32;
        }
        int res = 0;
        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            } else {
                if ((n + 1) % 4 == 0 && (n - 1) != 2) {
                    n += 1;
                } else {
                    n -= 1;
                }
            }
            res++;
        }
        return res;
    }
};