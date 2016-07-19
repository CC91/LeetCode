// 51. N-Queens

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> tmp(n, string(n, '.'));
        vector<bool> column(n, false);
        vector<bool> diag1(n * 2 - 1, false);
        vector<bool> diag2(n * 2 - 1, false);
        helper(0, n, column, diag1, diag2, tmp, res);
        return res;
    }
    
    void helper(int i, int n, vector<bool> &column, vector<bool> &diag1, 
    		vector<bool> &diag2, vector<string> tmp, vector<vector<string>> &res) {
        if (i == n) {
            res.push_back(tmp);
        }
        for (int j = 0; j < n; j++) {
            if (column[j] || diag1[i + j] || diag2[i - j + n - 1]) {
                continue;
            }
            tmp[i][j] = 'Q';
            column[j] = true;
            diag1[i + j] = true;
            diag2[i - j + n - 1] = true;
            helper(i + 1, n, column, diag1, diag2, tmp, res);
            tmp[i][j] = '.';
            column[j] = false;
            diag1[i + j] = false;
            diag2[i - j + n - 1] = false;
        }
    }
};