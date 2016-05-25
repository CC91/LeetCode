// 301. Remove Invalid Parentheses

class Solution {
public: // BFS
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_map<string, int> visited;
        visited[s]++;
        queue<string> q;
        q.push(s);
        bool found = false;
        while (!q.empty()) {
            s = q.front();
            q.pop();
            if (isValid(s)) {
                res.push_back(s);
                found = true;
            }
            if (found) {
                continue;
            }
            for (int i = 0; i < s.size(); i++) {
                if (s[i] != '(' && s[i] != ')') {
                    continue;
                }
                string t = s.substr(0, i) + s.substr(i + 1);
                if (!visited.count(t)) {
                    visited[t]++;
                    q.push(t);
                }
            }
        }
        return res;
    }
    
    bool isValid(string s) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                cnt++;
            }
            if (s[i] == ')' && cnt-- == 0) {
                return false;
            }
        }
        return cnt == 0;
    }
};