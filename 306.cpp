// 306. Additive Number

class Solution {
public: // |<---s1-->|<--s2-->|<--s3-->|, stoi(s1)+stoi(s2)=stoi(s3).
    bool isAdditiveNumber(string num) {
        int n = num.size();
        return helper(num, 0, n, "", "");
    }
    
    bool helper(string num, int pos, int n, string s1, string s2) {
        for (int i=pos; i<n; i++) {
            if (num[pos]=='0' && i>pos) return false; // leading zeros
            string s3 = num.substr(pos, i-pos+1);
            if (s1.empty() ||s2.empty()) {
                if (i+1<n && helper(num, i+1, n, s2, s3)) return true;
            } else if (stoll(s1)+stoll(s2)==stoll(s3)) {  // handle large integers
                if (i+1==n ||(i+1<n && helper(num, i+1, n, s2, s3))) return true;
            }
        }
        return false;
    }
};