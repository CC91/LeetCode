// 308. Range Sum Query 2D - Mutable

class NumMatrix {
private:
    int m;
    int n;
    vector<vector<int>> mat;
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }
        m = matrix.size();
        n = matrix[0].size();
        mat = vector<vector<int>> (m + 1, vector<int> (n + 1, 0));
        sum = vector<vector<int>> (m + 1, vector<int> (n + 1, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int diff = val - mat[row + 1][col + 1];
        for (int i = row + 1; i <= m; i += i & (-i)) {
            for (int j = col + 1; j <= n; j += j & (-j)) {
                sum[i][j] += diff;
            }
        }
        mat[row + 1][col + 1] = val;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2 + 1, col2 + 1) - getSum(row1, col2 + 1) - getSum(row2 + 1, col1) + getSum(row1, col1);
    }
    
    int getSum(int row, int col) {
        int res = 0;
        for (int i = row; i > 0; i -= i & (-i)) {
            for (int j = col; j > 0; j -= j & (-j)) {
                res += sum[i][j];
            }
        }
        return res;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);