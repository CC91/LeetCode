// 310. Minimum Height Trees

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) {
            return {0};
        }
        vector<int> res;
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n, vector<int> ());
        queue<int> q;
        for (auto &a : edges) {
            indegree[a.first]++;
            indegree[a.second]++;
            graph[a.first].push_back(a.second);
            graph[a.second].push_back(a.first);
        }
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1) {
                q.push(i);
            }
        }
        
        while (n > 2) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                int t = q.front();
                q.pop();
                n--;
                for (int &i :graph[t]) {
                    indegree[i]--;
                    if (indegree[i] == 1) {
                        q.push(i);
                    }
                }
            }
        }
        
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};