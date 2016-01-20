// 85. Maximal Rectangle

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> H(n, 0);
        vector<int> L(n, 0);
        vector<int> R(n, n);
        for (int i=0; i<m; i++) {
            int l = 0, r = n;
            for (int j=0; j<n; j++) { // left to right
                if (matrix[i][j]=='1') {
                    ++H[j];
                    L[j] = max(l, L[j]);
                } else {
                    l = j+1;
                    L[j]=H[j]=0;
                    R[j]=n;
                }
                
            }
            
            for (int k=n-1; k>=0; k--) { // right to left
                if (matrix[i][k]=='1') {
                    R[k] = min(r, R[k]);
                    res = max(res, H[k]*(R[k]-L[k]));
                } else r=k;
            }
        }
        return res;
    }
};