// 405. Convert a Number to Hexadecimal

class Solution {
public:
    string toHex(int num) {
        if (num == 0) {
            return "0";
        }
        string base[] = {"0", "1", "2", "3", "4", "5", "6", "7", 
            "8", "9", "a", "b", "c", "d", "e", "f"};
        string res = "";
        while (num != 0 && res.size() < 8) {
            res = base[num & 15] + res;
            num >>= 4;
        }
        return res;
    }
};