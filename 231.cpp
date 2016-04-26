// 231. Power of Two

class Solution {
public: // pow(2, x) numbers contain only one 1!
    bool isPowerOfTwo(int n) {
        return (n>0) && ((n&(n-1))==0); // negative numbers are not!
    }
};