// 154. Find Minimum in Rotated Sorted Array II

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while (start<end) {
            int mid = start+(end-start)/2;
            if (nums[mid]<nums[end]) end = mid; // right half is sorted
            else if (nums[mid]>nums[end]) start = mid+1; // left half is sorted
            else end--;
        }
        return nums[start];
    }
};