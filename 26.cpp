// 26. Remove Duplicates from Sorted Array

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i=1; i<nums.size();) {
            if (nums[i]==nums[i-1]) nums.erase(nums.begin()+i-1); // nums size may change so need to separate i
            else i++;
        }
        return nums.size();
    }
};


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for (int n:nums) {
            if (!i ||n>nums[i-1]) nums[i++] = n;
        }
        return i;
    }
};