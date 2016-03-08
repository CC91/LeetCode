// 90. Subsets II

class Solution {
public: // backtracking
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        sort(nums.begin(), nums.end());
        helper(nums, 0, tmp, res);
        return res;
    }
    
    void helper(vector<int>& nums, int start, vector<int> tmp, vector<vector<int>> &res) {
        for (int i=start; i<nums.size(); i++) {
            if (i>start && nums[i]==nums[i-1]) continue; // avoid duplicate results
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            helper(nums, i+1, tmp, res);
            tmp.pop_back();
        }
    }
};