// 269. Alien Dictionary

class Solution {
public:
    string alienOrder(vector<string>& words) {
        string res = "";
        set<pair<char, char>> s;
        set<char> letters;
        queue<char> q;
        vector<char> indegree(256, 0);
        for (auto w : words) {
            letters.insert(w.begin(), w.end());
        }
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = 0; j < min(words[i].size(), 
            	words[i + 1].size()); j++) {
                if (words[i][j] != words[i + 1][j]) {
                    s.insert({words[i][j], words[i + 1][j]});
                    break;
                }
            }
        }
        for (auto &a : s) {
            indegree[a.second]++;
        }
        for (auto &a : letters) {
            if (indegree[a] == 0) {
                res += a;
                q.push(a);
            }
        }
        while (!q.empty()) {
            char c = q.front();
            q.pop();
            for (auto &a : s) {
                if (a.first == c) {
                    if (--indegree[a.second] == 0) {
                        q.push(a.second);
                        res += a.second;
                    }
                }
            }
        }
        return res.size() == letters.size() ? res : "";
    }
};