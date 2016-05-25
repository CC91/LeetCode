// 210. Course Schedule II

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses, vector<int> (0));
        vector<int> indegree(numCourses, 0);
        for (auto p : prerequisites) {
            graph[p.second].push_back(p.first);
            indegree[p.first]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            res.push_back(t);
            for (auto g : graph[t]) {
                indegree[g]--;
                if (indegree[g] == 0) {
                    q.push(g);
                }
            }
        }
        if (res.size() != numCourses) {
            res.clear();
        }
        return res;
    }
};