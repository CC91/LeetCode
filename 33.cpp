// 33. Search in Rotated Sorted Array

class Solution {
public: // brute force
    int search(vector<int>& nums, int target) {
        for (int i=0; i<nums.size(); i++) {
            if (target==nums[i]) return i;
        }
        return -1;
    }
};


class Solution {
public: // binary search
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size()-1;
        while (i<=j) {
            int mid = (i+j)>>1;
            if (target==nums[mid]) return mid;
            else if (nums[mid]<nums[j]) {  // right part is sorted
                if (target>nums[mid] && target<=nums[j]) i = mid+1;
                else j = mid-1;
            } else {  // left part is sorted
                if (target>=nums[i] && target<nums[mid]) j = mid-1;
                else i = mid+1;
            }
        }
        return -1;
    }
};