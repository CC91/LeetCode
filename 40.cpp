// 40. Combination Sum II

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if (candidates[i]==candidates[i-1] && i>start) continue; // since each value can only be used once, it is i>start here not i>0
            if (candidates[i]<=target) {
                tmp.push_back(candidates[i]);
                helper(candidates, i+1, target-candidates[i], tmp, res); // i+1 not i
                tmp.pop_back();
            }
        }
    }
};