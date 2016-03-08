// 81. Search in Rotated Sorted Array II

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        while (i<=j) {
            int mid = i+(j-i)/2;
            if (nums[mid]==target) return true;
            else if (nums[i]<nums[mid]) { // left part is sorted
                if (nums[i]<=target && target<nums[mid]) j = mid-1;
                else i = mid+1;
            }
            else if (nums[i]>nums[mid]) { // right part is sorted
                if (nums[mid]<target && target<=nums[j]) i = mid+1;
                else j = mid-1;
            }
            else i++; // if there is duplicate, move to next i
        }
        return false;
    }
};