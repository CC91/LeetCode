// 238. Product of Array Except Self

class Solution {
public: // scan from left, get [0, i-1] production for each element at i, scan from right to get right elements multiplied for each i
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i=1; i<n; i++) res[i] = res[i-1]*nums[i-1];
        int tmp = 1;
        for (int i=n-2; i>=0; i--) {
            tmp *= nums[i+1];
            res[i] *= tmp;
        }
        return res;
    }
};