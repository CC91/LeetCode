// 12. Integer to Roman

class Solution {
public: // X: 10, L: 50, C: 100, D: 500, M: 1000
    string intToRoman(int num) {
        int integers[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romans[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res = "";
        for (int i=0; i<13; i++) {
            int cur = num/integers[i];
            while (cur) {
                res += romans[i];
                cur--;
            }
            num %= integers[i];
        }
        return res;
    }
};