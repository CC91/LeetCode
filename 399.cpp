// 399. Evaluate Division

class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> res;
        unordered_map<string, unordered_map<string, double>> m;
        for (int i = 0; i < values.size(); i++) {
            m[equations[i].first].insert({equations[i].second, values[i]});
            if (values[i] != 0) {
                m[equations[i].second].insert({equations[i].first, 1 / values[i]});
            }
        }
        for (auto q : queries) {
            unordered_set<string> s;
            double t = helper(q.first, q.second, m, s);
            if (t) {
                res.push_back(t);
            } else {
                res.push_back(-1);
            }
        }
        return res;
    }
    
    double helper(string a, string b, unordered_map<string, 
        unordered_map<string, double>> &m, unordered_set<string> &s) {
        if (m[a].find(b) != m[a].end()) {
            return m[a][b];
        }
        for (auto i : m[a]) {
            if (!s.count(i.first)) {
                s.insert(i.first);
                double t = helper(i.first, b, m, s);
                if (t) {
                    return i.second * t;
                }
            }
        }
        return 0;
    }
};