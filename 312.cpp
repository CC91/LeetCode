// 312. Burst Balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(), 0));
        for (int step=1; step<=n; step++) {
            for (int l=1; l<=n-step+1; l++) {
                int r = l+step-1;
                for (int k=l; k<=r; k++) {
                    dp[l][r] = max(dp[l][r], nums[l-1]*nums[k]*nums[r+1]+dp[l][k-1]+dp[k+1][r]);
                }
            }
        }
        return dp[1][n];
    }
};