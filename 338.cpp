// 338. Counting Bits

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1, 0);
        int base = 1;
        int prev = 1;
        for (int i = 1; i <= num; i++) {
            if (i == base) {
                dp[i] = prev = 1;
                base <<= 1;
            } else {
                dp[i] = dp[prev] + 1;
                prev += 1;
            }
        }
        return dp;
    }
};


class Solution {
public: // http://www.cnblogs.com/grandyang/p/5294255.html
    vector<int> countBits(int num) {
        vector<int> res{0};
        for (int i = 1; i <= num; i++) {
            if (i % 2 == 0) {
                res.push_back(res[i / 2]);
            }
            else {
                res.push_back(res[i / 2] + 1);
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num + 1, 0);
        for (int i = 1; i <= num; i++) {
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
};