// 18. 4Sum

class Solution {
public: // given 2 numbers, do 2sum to the rest of numbers
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        if (n<4) return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n-3; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue; // avoid duplicates
            for (int j=i+1; j<n-2; j++) {
                if (j>i+1 && nums[j]==nums[j-1]) continue;
                int start = j+1, end = n-1;
                int target2 = target-nums[i]-nums[j];
                while (start<end) {
                    int tmp = nums[start]+nums[end];
                    if (tmp<target2) start++;
                    else if (tmp>target2) end--;
                    else {
                        res.push_back(vector<int> {nums[i], nums[j], nums[start], nums[end]});
                        start++;
                        end--;
                        while (nums[start]==nums[start-1]) start++; // avoid duplicates
                        while (nums[end]==nums[end+1]) end--;
                    }
                }
            }
        }
        return res;
    }
};