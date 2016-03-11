// 228. Summary Ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0;
        while (i<nums.size()) {
            int j = 1;
            while (nums[i]+j==nums[i+j] && i+j<nums.size()) j++;
            res.push_back(j==1?to_string(nums[i]):to_string(nums[i])+"->"+to_string(nums[i+j-1]));
            i += j;
        }
        return res;
    }
};