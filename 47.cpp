// 47. Permutations II

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> res;
        helper(nums, 0, res);
        return vector<vector<int>> (res.begin(), res.end());
    }
    
    void helper(vector<int>& nums, int start, set<vector<int>> &res) {
        if (start == nums.size()) {
            res.insert(nums);
        }
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[start]) {
                continue;
            }
            swap(nums[i], nums[start]);
            helper(nums, start + 1, res);
            swap(nums[i], nums[start]);
        }
    }
};


class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
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
                    if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                        continue;
                    }
                    used[i] = true;
                    tmp.push_back(nums[i]);
                    helper(nums, start + 1, used, tmp, res);
                    used[i] = false;
                    tmp.pop_back();
                }
            }
        }
    		
};