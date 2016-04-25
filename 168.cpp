// 168. Excel Sheet Column Title

class Solution {
public: // decimal to 26
    string convertToTitle(int n) {
        string res = "";
        while (n) {
            res = char('A'+(n-1)%26)+res;
            n = (n-1)/26;
        }
        return res;
    }
};