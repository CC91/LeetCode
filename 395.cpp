// 395. Longest Substring with At Least K Repeating Characters

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        int i = 0;
        int n = s.size();
        while (i + k < n) {
            int m[26] = {0};
            int mask = 0;
            int idx = i;
            for (int j = i; j < n; j++) {
                int t = s[j] - 'a';
                if (++m[t] < k) {
                    mask |= (1 << t);
                } else {
                    mask &= (~(1 << t));
                }
                if (0 == mask) {
                    res = max(res, j - i + 1);
                    idx = j;
                }
            }
            i = idx + 1;
        }
        return res;
    }
};