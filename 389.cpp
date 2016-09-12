// 389. Find the Difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> m;
        for (auto a : s) {
            m[a]++;
        }
        for (auto a : t) {
            if (--m[a] < 0) {
                return a;
            }
        }
        return '0';
    }
};


class Solution {
public:
    char findTheDifference(string s, string t) {
        char res = '\0'; // or res = 0;
        for (auto a : s) {
            res ^= a;
        }
        for (auto a : t) {
            res ^= a;
        }
        return res;
    }
};