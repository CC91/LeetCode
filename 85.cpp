// 85. Maximal Rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> H(n, 0), L(n, 0), R(n, n);
        for (int i=0; i<m; i++) {
            int l = 0, r = n;
            for (int j=0; j<n; j++) { // scan from left to right
                if (matrix[i][j]=='1') {
                    H[j]++;
                    L[j] = max(l, L[j]);
                } else {
                    H[j] = L[j] = 0;
                    R[j] = n;
                    l = j+1;
                }
            }
            for (int k=n-1; k>=0; k--) { // then scan from right to left
                if (matrix[i][k]=='1') {
                    R[k] = min(r, R[k]);
                    res = max(res, H[k]*(R[k]-L[k]));
                } else {
                    r = k;
                }
            }
        }
        return res;
    }
};