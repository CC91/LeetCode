// 73. Set Matrix Zeroes

class Solution {
public: // O(m*n) time and space complexity
    void setZeroes(vector<vector<int>>& matrix) {
        if (matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        vector<bool> rflag(m, false), cflag(n, false);
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (matrix[i][j]==0) {
                    rflag[i] = true;
                    cflag[j] = true;
                }
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (rflag[i] ||cflag[j]) matrix[i][j] = 0;
            }
        }
    }
};


class Solution {
public: // O(m*n) time, O(1) space
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRow = false, firstCol = false;
        for (int i=0; i<m; i++) {
            if (matrix[i][0]==0) {
                firstCol = true;
                break;
            }
        }
        for (int i=0; i<n; i++) {
            if (matrix[0][i]==0) {
                firstRow = true;
                break;
            }
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][j]==0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for (int i=1; i<m; i++) {
            for (int j=1; j<n; j++) {
                if (matrix[i][0]==0 ||matrix[0][j]==0) matrix[i][j] = 0;
            }
        }
        if (firstRow) {
            for (int i=0; i<n; i++) matrix[0][i] = 0;
        }
        if (firstCol) {
            for (int i=0; i<m; i++) matrix[i][0] = 0;
        } 
    }
};