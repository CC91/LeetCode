// 43. Multiply Strings

class Solution {
public:
    string multiply(string num1, string num2) {
        string res(num1.size()+num2.size(), '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for (int i=0; i<num1.size(); i++) {
            int val = num1[i]-'0', carry = 0;
            for (int j=0; j<num2.size(); j++) {
                carry += (num2[j]-'0')*val+(res[i+j]-'0');
                res[i+j] = carry%10+'0';
                carry /= 10;
            }
            if (carry) res[i+num2.size()] = carry+'0';
        }
        reverse(res.begin(), res.end());
        int cnt = 0;
        while (cnt<res.size()-1 && res[cnt]=='0') cnt++; // if the result is 0, we need to keep a zero
        res.erase(0, cnt); // erase(value, length)
        return res;
    }
};