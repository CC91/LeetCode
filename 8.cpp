// 8. String to Integer (atoi)

class Solution {
public:
    int myAtoi(string str) {
        int i = 0, sign = 1, res = 0;
        while (str[i]==' ') i++;
        if (str[i]=='+') i++;
        else if (str[i]=='-') {
            sign = -1;
            i++;
        }
        while (isdigit(str[i])) {
            if (sign==1 && (res>INT_MAX/10 || (res==INT_MAX/10 && str[i]-'0'>=7))) return INT_MAX;
            if (sign==-1 && (-res<INT_MIN/10 || (-res==INT_MIN/10 && str[i]-'0'>=8))) return INT_MIN;
            res = res*10 +str[i]-'0';
            i++;
        }
        return res*sign;
    }
};