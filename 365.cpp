// 365. Water and Jug Problem

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        return z == 0 || (x + y >= z && z % helper(x, y) == 0);
    }
     
    int helper(int x, int y) {
        return y == 0? x : helper(y, x % y);
    }
};