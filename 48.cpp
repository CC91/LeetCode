// 48. Rotate Image

class Solution {
public: // transpose first then flip it
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n; i++) { // transpose
            for (int j=i; j<n; j++) swap(matrix[i][j], matrix[j][i]);
        }
        for (int i=0; i<n; i++) { // flip each row
            for (int j=0; j<n/2; j++) swap(matrix[i][j], matrix[i][n-j-1]);
        }
    }
};


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) swap(matrix[i][j], matrix[j][i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};