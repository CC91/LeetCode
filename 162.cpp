// 162. Find Peak Element

class Solution {
public: // brute force
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        for (int i=1; i<n-1; i++) {
            if (nums[i]>nums[i-1] && nums[i]>nums[i+1]) return i;
        }
        return nums[0]<nums[n-1]?(n-1):0; // there might be 1 or 2 elements in the array
    }
};


class Solution {
public: // binary search based on mid pointer
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-1;
        while (left<=right) {
            int mid = left+(right-left)/2;
            if (nums[mid]<nums[mid+1] && mid+1<n) left = mid+1;
            else if (nums[mid]<nums[mid-1] && mid>=1) right = mid-1;
            else return mid;
        }
        return left;
    }
};