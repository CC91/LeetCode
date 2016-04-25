// 67. Add Binary

class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1, j = b.size()-1, carry = 0;
        string res = "";
        while (i>=0 ||j>=0 ||carry) {
            if (i>=0) carry += a[i]=='0'?0:1;
            if (j>=0) carry += b[j]=='0'?0:1;
            res = (carry%2==0?'0':'1')+res;
            carry /= 2;
            i--;
            j--;
        }
        return res;
    }
};