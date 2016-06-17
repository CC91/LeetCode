// 254. Factor Combinations

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        helper(n, 2, {}, res);
        return res;
    }
    
    void helper(int n, int start, vector<int> tmp, vector<vector<int>> &res) {
        if (n == 1 && tmp.size() > 1) {
            res.push_back(tmp);
        }
        for (int i = start; i <= n; i++) {
            if (n % i == 0) {
                tmp.push_back(i);
                helper(n / i, i, tmp, res);
                tmp.pop_back();
            }
        }
    }
};