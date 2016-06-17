// 265. Paint House II

class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) {
            return 0;
        }
        int preMin = 0;
        int preSec = 0;
        int preIdx = -1;
        for (int i = 0; i < costs.size(); i++) {
            int curMin = INT_MAX;
            int curSec = INT_MAX;
            int curIdx = -1;
            for (int j = 0; j < costs[0].size(); j++) {
                costs[i][j] += (j == preIdx ? preSec : preMin);
                if (costs[i][j] < curMin) {
                    curSec = curMin;
                    curMin = costs[i][j];
                    curIdx = j;
                } else if (costs[i][j] < curSec) {
                    curSec = costs[i][j];
                }
            }
            preMin = curMin;
            preSec = curSec;
            preIdx = curIdx;
        }
        return preMin;
    }
};