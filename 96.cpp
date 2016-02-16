// 96. Unique Binary Search Trees

class Solution {
public: // f(n) = f(0)*f(n-1)+f(1)*f(n-2)+...+f(n-1)*f(0)
    int numTrees(int n) {
        vector<int> res(n+1, 0);
        res[0] = 1;
        for (int i=1; i<=n; i++) {
            for (int j=0; j<i; j++) res[i]+=res[j]*res[i-1-j];
        }
        return res[n];
    }
};