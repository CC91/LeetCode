// 153. Find Minimum in Rotated Sorted Array

class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};


class Solution {
public: // binary search
    int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        while (start<end) {
            int mid = start+(end-start)/2;
            if (nums[mid]<nums[end]) end = mid;
            else start = mid+1;
        }
        return nums[start];
    }
};