// 417. Pacific Atlantic Water Flow

class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        if (matrix.empty()) {
            return res;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> p(m, vector<bool> (n, false));
        vector<vector<bool>> a(m, vector<bool> (n, false));
        for (int i = 0; i < m; i++) {
            helper(matrix, p, INT_MIN, i, 0);
            helper(matrix, a, INT_MIN, i, n - 1);
        }
        for (int j = 0; j < n; j++) {
            helper(matrix, p, INT_MIN, 0, j);
            helper(matrix, a, INT_MIN, m - 1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (p[i][j] && a[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
    
    void helper(vector<vector<int>>& matrix, vector<vector<bool>>& visited,
    	int pre, int i, int j) {
        int m = matrix.size();
        int n = matrix[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] 
        	|| matrix[i][j] < pre) {
            return;
        }
        visited[i][j] = true;
        helper(matrix, visited, matrix[i][j], i + 1, j);
        helper(matrix, visited, matrix[i][j], i - 1, j);
        helper(matrix, visited, matrix[i][j], i, j + 1);
        helper(matrix, visited, matrix[i][j], i, j - 1);
    }
};