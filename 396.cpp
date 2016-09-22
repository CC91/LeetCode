// 396. Rotate Function

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int sum = 0;
        int t = 0;
        int res = 0;
        int n = A.size();
        for (int i = 0; i < n; i++) {
            t += i * A[i];
            sum += A[i];
        }
        res = t;
        for (int i = 1; i < n; i++) {
            t = t + sum - n * A[n - i];
            res = max(res, t);
        }
        return res;
    }
};