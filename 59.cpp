// 59. Spiral Matrix II

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n)); // initialize the res matrix!
        int left = 0, right = n-1, top = 0, down = n-1;
        while (left<=right && top<=down) {
            for (int i=left; i<=right; i++) res[top][i] = res[top][i-1]+1;
            top++;
            for (int i=top; i<=down; i++) res[i][right] = res[i-1][right]+1;
            right--;
            if (top<=down) {
                for (int i=right; i>=left; i--) res[down][i] = res[down][i+1]+1;
                down--;
            }
            if (left<=right) {
                for (int i=down; i>=top; i--) res[i][left] = res[i+1][left]+1;
                left++;
            }
        }
        return res;
    }
};