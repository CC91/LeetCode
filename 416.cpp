// 416. Partition Equal Subset Sum

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        sum /= 2;
        return helper(nums, 0, sum);
    }
    
    bool helper(vector<int>& nums, int start, int sum) {
        if (sum == 0) {
            return true;
        }
        for (int i = start; i < nums.size(); i++) {
            if (nums[i] <= sum) {
                sum -= nums[i];
                if (helper(nums, i + 1, sum)) {
                    return true;
                }
                sum += nums[i];
            }
        }
        return false;
    }
};


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2) {
            return false;
        }
        sum /= 2;
        vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int i = 1; i <= sum; i++) {
            for (auto a : nums) {
                if (a <= i) {
                    dp[i] = dp[i] || dp[i - a];
                }
            }
        }
        return dp.back();
    }
};