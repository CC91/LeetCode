// 383. Ransom Note

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int m[26] = {0};
        for (auto &a : magazine) {
            m[a - 'a']++;
        }
        for (auto &a : ransomNote) {
            if (--m[a - 'a'] < 0) {
                return false;
            }
        }
        return true;
    }
};