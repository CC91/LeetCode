// 368. Largest Divisible Subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> res;
        vector<int> dp(n, 1);
        vector<int> roots(n, 0);
        int start = 0;
        int max_len = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    roots[i] = j;
                }
            }
            if (max_len < dp[i]) {
                max_len = dp[i];
                start = i;
            }
        }
        for (int i = 0; i < max_len; i++) {
            res.push_back(nums[start]);
            start = roots[start];
        }
        return res;
    }
};