// 233. Number of Digit One  

class Solution {
public:
    int countDigitOne(int n) {
        int res = 0, a = 1, b = 1;
        while (n) {
            res += (n+8)/10*a+(n%10==1)*b;
            b += n%10*a;
            a *= 10;
            n /= 10;
        }
        return res;
    }
};


class Solution {
public:// http://www.cnblogs.com/grandyang/p/4629032.html
    int countDigitOne(int n) {
        int res = 0;
        for (long i=1; i<=n; i*=10) {
            long a = n/i, b = n%i;
            res += (a+8)/10*i+(a%10==1)*(b+1);
        }
        return res;
    }
};