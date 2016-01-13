// 77. Combinations

class Solution {
public: // backtracking
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        vector<vector<int>> res;
        comb(n, 1, k, tmp, res);
        return res;
    }
    
    void comb(int n, int start, int k, vector<int> &tmp, vector<vector<int>> &res) {
        if (k==0) {
            res.push_back(tmp);
            return;
        }
        
        for (int i=start; i<=n-k+1; i++) {
            tmp.push_back(i);
            comb(n, i+1, k-1, tmp, res);
            tmp.pop_back();
        }
    }
};