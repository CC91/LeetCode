// 243. Shortest Word Distance

class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p1 = -1;
        int p2 = -1;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1) {
                p1 = i;
            }
            if (words[i] == word2) {
                p2 = i;
            }
            if (p1 != -1 && p2 != -1) {
                res = min(res, abs(p1 - p2));
            }
        }
        return res;
    }
};


class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int p = -1;
        int res = INT_MAX;
        for (int i = 0; i < words.size(); i++) {
            if (words[i] == word1 || words[i] == word2) {
                if (p != -1 && words[p] != words[i]) {
                    res = min(res, abs(i - p));
                }
                p = i;
            }
        }
        return res;
    }
};