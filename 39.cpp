// 39. Combination Sum

class Solution {
public: // backtracking
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) return res;
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, tmp, res);
        return res;
    }
    
    void helper(vector<int>& candidates, int start, int target, vector<int> tmp, vector<vector<int>> &res) {
        if (target==0) {
            res.push_back(tmp);
            return;
        }
        for (int i=start; i<candidates.size(); i++) {
            if (candidates[i]==candidates[i-1] && i>0) continue; // avoid duplicates
            if (candidates[i]<=target) {
                tmp.push_back(candidates[i]);
                helper(candidates, i, target-candidates[i], tmp, res);
                tmp.pop_back();
            }
        }
    }
};