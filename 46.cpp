// 46. Permutations

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        helper(nums, 0, res);
        return res;
    }
    
    void helper(vector<int>& nums, int start, vector<vector<int>> &res) {
        if (start == nums.size()) {
            res.push_back(nums);
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            helper(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        helper(nums, 0, used, tmp, res);
        return res;
    }
    
    void helper(vector<int>& nums, int start, vector<bool> &used, 
    		vector<int> tmp, vector<vector<int>> &res) {
        if (start == nums.size()) {
            res.push_back(tmp);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                tmp.push_back(nums[i]);
                helper(nums, start + 1, used, tmp, res);
                used[i] = false;
                tmp.pop_back();
            }
        }
    }
};