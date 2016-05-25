// 227. Basic Calculator II  

class Solution {
public:
    int calculate(string s) {
        istringstream ss(s + '+');
        int val;
        int mul;
        char op;
        int res = 0;
        int sign = 1;
        ss >> val;
        while (ss >> op) {
            if (op == '+' || op == '-') {
                res += sign * val;
                sign = 44 - op; // '+' is 43, '-' is 45
                ss >> val;
            } else {
                ss >> mul;
                if (op == '*') {
                    val *= mul;
                } else {
                    val /=  mul;
                }
            }
        }
        return res;
    }
};