// 266. Palindrome Permutation

class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        int odd = 0;
        for (auto &a : s) {
            m[a]++;
        }
        for (auto it = m.begin(); it != m.end(); it++) {
            if (it -> second % 2) {
                odd++;
            }
        }
        return odd == 0 || (s.size() % 2 && odd == 1);
    }
};


class Solution {
public:
    bool canPermutePalindrome(string s) {
        set<char> t;
        for (auto &a : s) {
            if (t.count(a)) {
                t.erase(a);
            } else {
                t.insert(a);
            }
        }
        return t.empty() || t.size() == 1;
    }
};


class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> t;
        for (auto &a : s) {
            t.flip(a);
        }
        return t.count() < 2;
    }
};