// 213. House Robber II

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.empty() ? 0 : nums[0];
        }
        int n = nums.size();
        return max(helper(nums, 0, n - 1), helper(nums, 1, n));
    }
    
    int helper(vector<int>& nums, int start, int end) {
        if (start > end) {
            return nums[start];
        }
        vector<int> dp(end, 0);
        dp[start] = nums[start];
        dp[start + 1] = max(nums[start], nums[start + 1]);
        for (int i = start + 2; i < end; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp.back();
    }
};