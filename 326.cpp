// 326. Power of Three

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        if (n==1) return true;
        if (n%3==0) return isPowerOfThree(n/3);
        else return false;
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n<=0) return false;
        while (n!=1) {
            if (n%3!=0) break;
            n /= 3;
        }
        return n==1;
    }
};


class Solution {
public:
    bool isPowerOfThree(int n) {
        return fmod(log10(n)/log10(3), 1)==0;
    }
};