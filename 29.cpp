// 29. Divide Two Integers

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (!divisor) return dividend>0?INT_MAX:INT_MIN;
        if (dividend==INT_MIN && divisor==-1) return INT_MAX; // overflow
        int sign = 1, i = 0, res = 0;
        if ((dividend>0 && divisor<0) || (dividend<0 && divisor>0)) sign = -1;
        unsigned long long dvd = abs((long long) dividend), dvs = abs((long long) divisor);
        while (dvs<<(i+1)<=dvd) i++;
        while (dvd>=dvs) {
            if (dvd>=dvs<<i) {
                res += 1<<i;
                dvd -= dvs<<i;
            }
            i--;
        }
        return sign>0?res:0-res;
    }
};