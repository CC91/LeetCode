// 80. Remove Duplicates from Sorted Array II

class Solution {
public: // update the cur pointer which indicates the latest place that no more than 2 duplicates
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n<3) return n;
        int cur = 1;
        for (int i=2; i<n; i++) {
            if (nums[cur-1]!=nums[i]) nums[++cur] = nums[i];
        }
        return cur+1;
    }
};