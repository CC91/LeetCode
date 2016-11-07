// 415. Add Strings

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry = 0;
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        string res = "";
        while (i >= 0 || j >= 0) {
            if (i >= 0) {
                carry += num1[i--] - '0';
            }
            if (j >= 0) {
                carry += num2[j--] - '0';
            }
            res = to_string(carry % 10) + res;
            carry /= 10;
        }
        if (carry) {
            res = to_string(carry) + res;
        }
        return res;
    }
};