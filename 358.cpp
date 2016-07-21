// 358. Rearrange String k Distance Apart

class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) {
            return str;
        }
        unordered_map<char, int> m;
        priority_queue<pair<int, char>> q;
        string res = "";
        int n = str.size();
        for (auto a : str) {
            m[a]++;
        }
        for (auto a : m) {
            q.push({a.second, a.first});
        }
        while (!q.empty()) {
            int cnt = min(k, n);
            vector<pair<int, char>> tmp;
            for (int i = 0; i < cnt; i++) {
                if (q.empty()) {
                    return "";
                }
                auto t = q.top();
                q.pop();
                res += t.second;
                if (--t.first > 0) {
                    tmp.push_back(t);
                }
                n--;
            }
            for (auto a : tmp) {
                q.push(a);
            }
        }
        return res;
    }
};