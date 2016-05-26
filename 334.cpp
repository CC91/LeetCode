// 334. Increasing Triplet Subsequence

class Solution {
public: // DP
    bool increasingTriplet(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    if (dp[i] >= 3) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};


class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        for (int n : nums) {
            if (m1 >= n) {
                m1 = n;
            } else if (m2 >= n) {
                m2 = n;
            } else {
                return true;
            }
        }
        return false;
    }
};