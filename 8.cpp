// 8. String to Integer (atoi)

class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int i=0, res=0, sign=1;
        
        while (str[i]==' ') i++;
        
        if (str[i]=='-') {
            sign=-1;
            i++;
        }
        else if (str[i]=='+') i++;
        
        while (isdigit(str[i])) {
            if (sign==1 && res>INT_MAX/10) return INT_MAX;
            if (sign==1 && res==INT_MAX/10 && str[i]-'0'>=7) return INT_MAX;
            if (sign==-1 && -res<INT_MIN/10) return INT_MIN;
            if (sign==-1 && -res==INT_MIN/10 && str[i]-'0'>=8) return INT_MIN;
            res = res*10+str[i]-'0';
            i++;
        }
        return res*sign;
    }
};