// 325. Maximum Size Subarray Sum Equals k

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> m;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum == k) {
                res = max(res, i + 1);
            }
            if (m.count(sum - k)) {
                res = max(res, i - m[sum - k]);
            } else if (!m.count(sum)) {
                m[sum] = i;
            }
        }
        return res;
    }
};