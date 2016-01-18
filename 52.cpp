// 52. N-Queens II

class Solution {
    int res;
public:
    int totalNQueens(int n) {
        vector<int> col(n, 0);
        vector<int> cross1(n*2-1, 0);
        vector<int> cross2(n*2-1, 0);
        res = 0;
        dfs(0, n, col, cross1, cross2);
        return res;
    }
    
    void dfs(int i, int n, vector<int> &col, vector<int> &cross1, vector<int> &cross2) {
        if (i==n) {
            ++res;
            return;
        }
        for (int j=0; j<n; j++) {
            bool set = col[j]==0 && cross1[i+j]==0 && cross2[i-j+n-1]==0;
            if (!set) continue;
            col[j]=cross1[i+j]=cross2[i-j+n-1]=1;
            dfs(i+1, n, col, cross1, cross2);
            col[j]=cross1[i+j]=cross2[i-j+n-1]=0;
        }
    }
};