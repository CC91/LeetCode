// 400. Nth Digit

class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;
        int first = 1;
        long base = 9;
        while (n > base * len) {
            n -= base * len;
            len++;
            base *= 10;
            first *= 10;
        }
        first += (n - 1) / len;
        string s = to_string(first);
        return s[(n - 1) % len] - '0';
    }
};