// 242. Valid Anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};


class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size()!=t.size()) return false;
        int m[26] = {0};
        for (char c1:s) m[c1-'a']++;
        for (char c2:t) if (--m[c2-'a']<0) return false;
        return true;
    }
};