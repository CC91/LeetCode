// 409. Longest Palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        bool mid = false;
        unordered_map<char, int> m;
        for (auto c : s) {
            m[c]++;
        }
        for (auto a : m) {
            res += a.second;
            if (a.second % 2 == 1) {
                res -= 1;
                mid = true;
            }
        }
        return mid ? res + 1 : res;
    }
};


class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<int> t;
        for (auto c: s) {
            if (!t.count(c)) {
                t.insert(c);
            } else {
                t.erase(c);
            }
        }
        return s.size() - max(0, (int)t.size() - 1);
    }
};