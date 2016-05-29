// 351. Android Unlock Patterns

class Solution {
public:
    int numberOfPatterns(int m, int n) {
        return helper(m, n, 0, 1, 1);
    }
    
    int helper(int m, int n, int used, int x, int y) {
        int res = m <= 0;
        if (!n) {
            return 1;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int I = x + i;
                int J = y + j;
                int used2 = used | (1 << (i * 3 + j));
                if (used2 > used && (I % 2 || J % 2 || used2 & (1 << (I / 2 * 3 + J / 2)))) {
                    res += helper(m - 1, n - 1, used2, i, j);
                }
            }
        }
        return res;
    }
};