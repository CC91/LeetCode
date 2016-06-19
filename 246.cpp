// 246. Strobogrammatic Number

class Solution {
public:
    bool isStrobogrammatic(string num) {
        int l = 0;
        int r = num.size() - 1;
        while (l <= r) {
            if (num[l] == num[r]) {
                if (num[l] != '0' && num[l] != '1' && num[l] != '8') {
                    return false;
                }
            } else if ((num[l] != '6' || num[r] != '9') && 
            	(num[l] != '9' || num[r] != '6')) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};