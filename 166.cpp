// 166. Fraction to Recurring Decimal

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator==0) return "0";
        string res;
        long long int n = numerator, d = denominator; // if there is INT_MIN, convert it to positive will cause overflow
        if (n<0 ^ d<0) res = '-'; // XOR to check if there is negative
        n = abs(n), d = abs(d);
        res += to_string(n/d);
        long long int r = n%d; // r might be INT_MIN
        if (r==0) return res;
        else res += '.';
        unordered_map<int, int> m; // key is the remainder, value is the position of remainder first appeared in the res
        while (r) {
            if (m.count(r)) {
                res.insert(m[r], "("); // when fraction repeats, add ()
                res += ")";
                break;
            }
            m[r] = res.size();
            r *= 10;
            res += to_string(r/d);
            r %= d;
        }
        return res;
    }
};