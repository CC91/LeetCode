// 134. Gas Station

class Solution {
public: // http://bangbingsyb.blogspot.com/2014/11/leetcode-gas-station.html
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0, curSum = 0, nextSum = 0;
        for (int i=0; i<cost.size(); i++) {
            curSum += gas[i]-cost[i];
            nextSum += gas[i]-cost[i];
            if (curSum<0) {
                res = i+1;
                curSum = 0;
            }
        }
        if (nextSum<0) return -1;
        return res;
    }
};