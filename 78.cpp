// 78. Subsets

class Solution {
public: // backtracking
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        sort(nums.begin(), nums.end());
        helper(nums, 0, tmp, res);
        return res;
    }
    
    void helper(vector<int>& nums, int start, vector<int> tmp, vector<vector<int>> &res) {
        for (int i=start; i<nums.size(); i++) {
            tmp.push_back(nums[i]);
            res.push_back(tmp);
            helper(nums, i+1, tmp, res);
            tmp.pop_back(); // backtracking
        }
    }
};


class Solution {
public: // add elements to subsets
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        res.push_back(tmp);
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            int n = res.size();
            for (int j=0; j<n; j++) {
                tmp = res[j];
                tmp.push_back(nums[i]);
                res.push_back(tmp);
            }
        }
        return res;
    }
};


class Solution { // bit manipulation
public: // non-descending or ascending order should sort first!
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i=0; i<pow(2, n); i++) {
            res.push_back(helper(nums, i));
        }
        return res;
    }
    
    vector<int> helper(vector<int>& nums, int n) {
        int i = 0;
        vector<int> r;
        while (n) {
            if (n&1) r.push_back(nums[i]);
            n >>= 1;
            i++;
        }
        return r;
    }
};