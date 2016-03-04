// 75. Sort Colors

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(), left = 0, right = n-1, i = 0; // left/right is the bound of 0/1, i is the scan pointer
        while (i<=right) {
            if (nums[i]==0) swap(nums[i++], nums[left++]); // 1s can only be put in the middle, so i++ is fine
            else if (nums[i]==2) swap(nums[i], nums[right--]); // after the swap, nums[i] is unknow, so i doesn't increase
            else i++;
        }
    }
};