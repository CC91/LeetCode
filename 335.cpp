// 335. Self Crossing  

class Solution {
public:// https://www.hrwhisper.me/leetcode-self-crossing/
    bool isSelfCrossing(vector<int>& x) {
        for (int i=3; i<x.size(); i++) {
            if (x[i-3]>=x[i-1] && x[i]>=x[i-2]) return true;
            else if (i>=4 && x[i-3]==x[i-1] && x[i-4]+x[i]>=x[i-2]) return true;
            else if (i>=5 && x[i-5]+x[i-1]>=x[i-3] && x[i-4]+x[i]>=x[i-2] && x[i-2]>=x[i-4] && x[i-3]>=x[i-1]) return true;
        }
        return false;
    }
};


class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        x.insert(x.begin(), 4, 0);
        int i = 4;
        int len = x.size();
        for (; i < len && x[i] > x[i - 2]; i++); // check outer spiral
        if (i == len) {
            return false;
        }
        
        if (x[i - 4] + x[i] >= x[i - 2] ) { // check inner spiral
            x[i - 1] -= x[i - 3];
        }
        for (i++; i < len && x[i] < x[i - 2]; i++);
        return i != len;
    }
};