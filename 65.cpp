// 65. Valid Number

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        if (n==0) return false;
        int i = 0, cnt_num = 0, cnt_point = 0;
        while (s[i]==' ') i++;
        if (s[i]=='+' ||s[i]=='-') i++;
        while (isdigit(s[i]) ||s[i]=='.') s[i++]=='.'?cnt_point++:cnt_num++;
        if (cnt_num<1 ||cnt_point>1) return false;
        if (s[i]=='e') {
            i++;
            cnt_num = cnt_point = 0;
            if (s[i]=='+' ||s[i]=='-') i++;
            while (isdigit(s[i]) ||s[i]=='.') s[i++]=='.'?cnt_point++:cnt_num++;
            if (cnt_num<1 ||cnt_point>0) return false;
        }
        while (s[i]==' ') i++;
        return i==n;
    }
};