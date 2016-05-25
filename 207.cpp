// 207. Course Schedule

class Solution {
public: // DFS
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int> (0));
        vector<int> visit(numCourses, 0);
        for (auto p : prerequisites) {
            graph[p.second].push_back(p.first);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!helper(graph, visit, i)) {
                return false;
            }
        }
        return true;
    }
    
    bool helper(vector<vector<int>> &graph, vector<int> &visit, int i) {
        if (visit[i] == -1) {
            return false;
        }
        if (visit[i] == 1) {
            return true;
        }
        visit[i] = -1;
        for (auto g : graph[i]) {
            if (!helper(graph, visit, g)) {
                return false;
            }
        }
        visit[i] = 1;
        return true;
    }
};



class Solution {
public: // BFS
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
            for (auto g : graph[t]) {
                indegree[g]--;
                if (indegree[g] == 0) {
                    q.push(g);
                }
            }
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] != 0) {
                return false;
            }
        }
        return true;
    }
};