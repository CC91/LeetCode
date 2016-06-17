// 267. Palindrome Permutation II

class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<string> res;
        unordered_map<char, int> m;
        for (char c : s) {
            m[c]++;
        }
        string t = "";
        string mid = "";
        for (auto it : m) {
            if (it.second % 2) {
                mid += it.first;
            }
            t += string(it.second / 2, it.first);
            if (mid.size() > 1) {
                return res;
            }
        }
        helper(t, mid, 0, res);
        return res;
    }
    
    void helper(string &t, string mid, int start, vector<string> &res) {
        if (start >= t.size()) {
            res.push_back(t + mid + string(t.rbegin(), t.rend()));
        }
        for (int i = start; i < t.size(); i++) {
            if (i != start && t[i] == t[start]) {
                continue;
            }
            swap(t[i], t[start]);
            helper(t, mid, start + 1, res);
            swap(t[i], t[start]);
        }
    }
};