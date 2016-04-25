// 171. Excel Sheet Column Number

class Solution {
public: // 26 to decimal
    int titleToNumber(string s) {
        int res = 0;
        for (char c:s) res = res*26+c-'A'+1;
        return res;
    }
};