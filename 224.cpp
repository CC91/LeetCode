// 224. Basic Calculator

class Solution {
public:// sign() is the innermost scope needs to be calculated, "(" duplicates the current sign and ")" drop out the current sign
    int calculate(string s) {
        int res = 0;
        vector<int> sign(2, 1);
        for (int i=0; i<s.size(); i++) {
            int num = 0;
            if (isdigit(s[i])) {
                while (isdigit(s[i]) && i<s.size()) {
                    num = num*10+s[i++]-'0';
                }
                i--;
                res += sign.back()*num;
                sign.pop_back();
            }
            else if (s[i]==')') sign.pop_back();
            else if (s[i]!=' ') sign.push_back(sign.back()*(s[i]=='-'?-1:1));
        }
        return res;
    }
};