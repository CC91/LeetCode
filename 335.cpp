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