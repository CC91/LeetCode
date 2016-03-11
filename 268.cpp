// 268. Missing Number

class Solution {
public: // arithmetic progression sum 
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i:nums) sum += i;
        return 0.5*n*(n+1)-sum;
    }
};


class Solution {
public: // bit manipulation 
    int missingNumber(vector<int>& nums) {
        int res = 0;
        for (int i=0; i<nums.size(); i++) res ^= (i+1)^nums[i]; // since array begins from 0, (i+1)*nums[i]
        return res;
    }
};


class Solution {
public: // binary search, not best
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size();
        while (i<j) {
            int mid = i+(j-i)/2;
            if (nums[mid]>mid) j = mid;
            else i = mid+1;
        }
        return j;
    }
};