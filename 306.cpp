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



class Solution {
public:
    bool isAdditiveNumber(string num) {
        for (int i = 1; i < num.size(); i++) {
            for (int j = i + 1; j < num.size(); j++) {
                string s1 = num.substr(0, i);
                string s2 = num.substr(i, j - i);
                if ((s1.size() > 1 && s1[0] == '0') || (s2.size() > 1 && s2[0] == '0')) {
                    continue;
                }
                long long n1 = stoll(s1);
                long long n2 = stoll(s2);
                long long n3 = n1 + n2;
                string s3 = to_string(n1 + n2);
                string tmp = s1 + s2 + s3;
                while (tmp.size() < num.size()) {
                    n1 = n2;
                    n2 = n3;
                    n3 = n1 + n2;
                    s3 = to_string(n3);
                    tmp += s3;
                }
                if (tmp == num) {
                    return true;
                }
            }
        }
        return false;
    }
};