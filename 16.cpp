// 16. 3Sum Closest

class Solution {
public: // 2 pointers, sort list first!
    int threeSumClosest(vector<int>& nums, int target) {
        int len = nums.size();
        if (len<3) return INT_MAX;
        int minDiff = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i=0; i<len-2; i++) {
            int j = i+1, k = len-1;
            while (j<k) {
                int diff = nums[i]+nums[j]+nums[k]-target;
                if (diff==0) return target;
                if (abs(diff)<abs(minDiff)) minDiff = diff; // notice the abs condition!
                if (diff<0) j++;
                else k--;
            }
        }
        return minDiff+target;
    }
};