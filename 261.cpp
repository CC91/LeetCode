// 261. Graph Valid Tree

class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> g(n, vector<int> ());
        vector<bool> visited(n, false);
        for (auto e : edges) {
            g[e.first].push_back(e.second);
            g[e.second].push_back(e.first);
        }
        if (!helper(g, visited, 0, -1)) {
            return false;
        }
        for (auto v : visited) {
            if (!v) {
                return false;
            }
        }
        return true;
    }
    
    bool helper(vector<vector<int>> &g, vector<bool> &visited, int cur, int pre) {
        if (visited[cur]) {
            return false;
        }
        visited[cur] = true;
        for (auto a : g[cur]) {
            if (a != pre) {
                if (!helper(g, visited, a, cur)) {
                    return false;
                }
            }
        }
        return true;
    }
};


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> roots(n, -1);
        for (auto a : edges) {
            int x = helper(roots, a.first);
            int y = helper(roots, a.second);
            if (x == y) {
                return false;
            }
            roots[x] = y;
        }
        return n - 1 == edges.size();
    }
    
    int helper(vector<int> &roots, int i) {
        while (roots[i] != -1) {
            i = roots[i];
        }
        return i;
    }
};