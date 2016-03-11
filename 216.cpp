// 216. Combination Sum III

class Solution {
public: // backtracking, template
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (n==0) return res;
        vector<int> tmp;
        helper(k, 1, n, tmp, res);
        return res;
    }
    
    void helper(int k, int start, int n, vector<int> tmp, vector<vector<int>> &res) {
        if (n==0 && tmp.size()==k) {
            res.push_back(tmp);
            return;
        }
        
        for (int i=start; i<=9; i++) {
            tmp.push_back(i);
            helper(k, i+1, n-i, tmp, res);
            tmp.pop_back();
        }
    }
};