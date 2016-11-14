// 424. Longest Repeating Character Replacement

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int start = 0;
        int m[26] = {0};
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            cnt = max(cnt, ++m[s[i] - 'A']);
            while (i - start + 1 - cnt > k) {
                --m[s[start++] - 'A'];
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};