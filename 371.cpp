// 371. Sum of Two Integers

class Solution {
public:
    int getSum(int a, int b) {
        if (a == 0 || b == 0) {
            return a == 0 ? b : a;
        }
        int sum = a ^ b;
        int carry = (a & b) << 1;
        return getSum(sum, carry);
    }
};


class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};