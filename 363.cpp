// 363. Max Sum of Rectangle No Larger Than K

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int res = INT_MIN;
        for (int l = 0; l < n; l++) {
            vector<int> sum(m, 0);
            for (int r = l; r < n; r++) {
                for (int i = 0; i < m; i++) {
                    sum[i] += matrix[i][r];
                }
                set<int> s;
                s.insert(0);
                int curSum = 0;
                int curMax = INT_MIN;
                for (auto a : sum) {
                    curSum += a;
                    set<int>::iterator it = s.lower_bound(curSum - k);
                    if (it != s.end()) {
                        curMax = max(curMax, curSum - *it);
                    }
                    s.insert(curSum);
                }
                res = max(res, curMax);
            }
        }
        return res;
    }
};