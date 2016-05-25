// 332. Reconstruct Itinerary

class Solution {
public: // DFS
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> res;
        unordered_map<string, multiset<string>> m;
        for (auto t : tickets) {
            m[t.first].insert(t.second);
        }
        helper(m, "JFK", res);
        return vector<string> (res.rbegin(), res.rend());
    }
    
    void helper(unordered_map<string, multiset<string>> &m, string s, vector<string> &res) {
        while (m[s].size()) {
            string t = *m[s].begin();
            m[s].erase(m[s].begin());
            helper(m, t, res);
        }
        res.push_back(s);
    }
};