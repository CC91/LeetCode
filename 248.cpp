// 248. Strobogrammatic Number III

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int res = 0;
        helper(low, high, "", res);
        helper(low, high, "0", res);
        helper(low, high, "1", res);
        helper(low, high, "8", res);
        return res;
    }
    
    void helper(string low, string high, string tmp, int &res) {
        if (tmp.size() >= low.size() && tmp.size() <= high.size()) {
            if ((tmp.size() == low.size() && tmp.compare(low) < 0) || 
            	(tmp.size() == high.size() && tmp.compare(high) > 0)) {
                return;
            }
            if (!(tmp.size() > 1 && tmp[0] == '0')) {
                res++;
            }
        }
        if (tmp.size() + 2 > high.size()) {
            return;
        }
        helper(low, high, "0" + tmp + "0", res);
        helper(low, high, "1" + tmp + "1", res);
        helper(low, high, "8" + tmp + "8", res);
        helper(low, high, "6" + tmp + "9", res);
        helper(low, high, "9" + tmp + "6", res);
    }
};