// 323. Number of Connected Components in an Undirected Graph

class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int res = 0;
        vector<vector<int>> g(n);
        vector<bool> visited(n, false);
        for (auto &a : edges) {
            g[a.first].push_back(a.second);
            g[a.second].push_back(a.first);
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                res++;
                helper(g, visited, i);
            }
        }
        return res;
    }
    
    void helper(vector<vector<int>> &g, vector<bool> &visited, int i) {
        if (visited[i]) {
            return;
        }
        visited[i] = true;
        for (int j = 0; j < g[i].size(); j++) {
            helper(g, visited, g[i][j]);
        }
    }
};