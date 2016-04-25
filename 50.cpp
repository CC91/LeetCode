// 50. Pow(x, n) 

class Solution {
public: // x^n = x^(n/2)*x^(n/2)*x^(n%2)
    double myPow(double x, int n) {
        if (n>0) return helper(x, n);
        else return 1/helper(x, n);
    }
    
    double helper(double x, int n) {
        if (n==0) return 1;
        double res = helper(x, n/2);
        res *= res;
        if (n%2) res *= x;
        return res;
    }
};