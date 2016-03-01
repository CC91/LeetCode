// 15. 3Sum

class Solution {
public: // 2 pointers, so need to sort the list first!
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int len = nums.size();
        if (len<3) return res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<len-2; i++) {
            if (i>0 && nums[i]==nums[i-1]) continue; // check duplicates
            int a = nums[i];
            int j = i+1, k = len-1;
            while (j<k) {
                int b = nums[j], c = nums[k];
                if (a+b+c==0) {
                    res.push_back(vector<int> {a, b, c});
                    while (j<len && nums[j]==b) j++; // check duplicates
                    while (k<len && nums[k]==c) k--;
                }
                else if (a+b+c>0) k--;
                else j++;
            }
        }
        return res;
    }
};