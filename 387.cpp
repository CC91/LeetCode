// 387. First Unique Character in a String

class Solution {
public:
    int firstUniqChar(string s) {
        int m[26] = {0};
        for (auto a : s) {
            m[a - 'a']++;
        }
        for (int i = 0; i < s.size(); i++) {
            if (m[s[i] - 'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};