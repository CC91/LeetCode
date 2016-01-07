// 7. Reverse Integer

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while (x) {
            if (res>INT_MAX/10 || res<INT_MIN/10) return 0; // res*10>INT_MAX might be overflow, so it has to be res>INT_MAX/10, same with INT_MIN!
            res = res*10+x%10;
            x/=10;
        }
        return res;
    }
};