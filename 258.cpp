// 258. Add Digits

class Solution {
public: // https://en.wikipedia.org/wiki/Digital_root
    int addDigits(int num) {
        return 1+(num-1)%9;
    }
};


class Solution {
public: // naive
    int addDigits(int num) {
        while (num>9) {
            int sum = 0;
            while (num) {
                sum += num%10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};