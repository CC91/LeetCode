// 403. Frog Jump

class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, unordered_set<int>> m;
        m[0].insert(0);
        vector<int> dp(stones.size(), 0);
        int k = 0;
        for (int i = 1; i < stones.size(); i++) {
            while (dp[k] + 1 < stones[i] - stones[k]) {
                k++;
            }
            for (int j = k; j < i; j++) {
                int d = stones[i] - stones[k];
                if (m[j].count(d) || m[j].count(d - 1) || m[j].count(d + 1)) {
                    m[i].insert(d);
                    dp[i] = max(dp[i], d);
                    break;
                }
            }
        }
        return dp.back() > 0;
    }
};