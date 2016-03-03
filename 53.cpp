// 53. Maximum Subarray

class Solution {
public: // DP, each idx can be a starting point of the maximum subarray which depends on the pos/neg
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), curSum = nums[0], res = nums[0];
        for (int i=1; i<n; i++) {
            curSum = curSum<=0?nums[i]:nums[i]+curSum;
            res = max(res, curSum);
        }
        return res;
    }
};


class Solution {
public: // greedy
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(), sum = 0, res = nums[0];
        for (int i=0; i<n; i++) {
            sum += nums[i];
            res = max(sum, res);
            sum = max(sum, 0);
        }
        return res;
    }
};


class Solution {
public: // divide and conquer
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        return helper(nums, 0, nums.size()-1, res);
    }
    
    int helper(vector<int>& nums, int left, int right, int &res) {
        if (left>right) return INT_MIN;
        int mid = left+(right-left)/2;
        int lmax = helper(nums, left, mid-1, res);
        int rmax = helper(nums, mid+1, right, res);
        res = max(res, max(lmax, rmax));
        int lsum = 0, sum = 0;
        for (int i=mid-1; i>=left; i--) {
            sum += nums[i];
            if (sum>lsum) lsum = sum;
        }
        int rsum = 0;
        sum = 0;
        for (int i=mid+1; i<=right; i++) {
            sum += nums[i];
            if (sum>rsum) rsum = sum;
        }
        res = max(res, lsum+rsum+nums[mid]);
        return res;
    }
};