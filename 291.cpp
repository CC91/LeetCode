// 291. Word Pattern II

class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        unordered_map<char, string> m;
        set<string> s;
        return helper(pattern, 0, str, 0, m, s);
    }
    
    bool helper(string pattern, int p, string str, int q, unordered_map<char, string> &m, set<string> &s) {
        if (p == pattern.size() && q == str.size()) {
            return true;
        }
        if (p == pattern.size() || q == str.size()) {
            return false;
        }
        
        char c = pattern[p];
        for (int i = q; i < str.size(); i++) {
            string t = str.substr(q, i - q + 1);
            if (m.count(c) && m[c] == t) {
                return helper(pattern, p + 1, str, i + 1, m, s);
            } else if (!m.count(c)) {
                if (s.count(t)) {
                    continue;
                }
                m[c] = t;
                s.insert(t);
                if (helper(pattern, p + 1, str, i + 1, m, s)) {
                    return true;
                }
                m.erase(c);
                s.erase(t);
            }
        }
        return false;
    }
};