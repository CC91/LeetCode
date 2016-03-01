// 31. Next Permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()<2) return;
        int n = nums.size();
        int i = n-2;
        while (i>=0 && nums[i]>=nums[i+1]) i--; // find the position where the list decreases from right to left
        if (i<0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = i+1;
        while (j<n && nums[i]<nums[j]) j++; // can't ignore!
        j--;
        swap(nums[i], nums[j]);
        sort(nums.begin()+i+1, nums.end());
    }
};