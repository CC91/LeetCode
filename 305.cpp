// 305. Number of Islands II

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m <= 0 || n <= 0 || positions.empty()) {
            return res;
        }
        vector<int> roots(m * n, -1);
        vector<vector<int>> dir{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int count = 0;
        for (auto &p : positions) {
            int id = n * p.first + p.second;
            roots[id] = id;
            count++;
            for (auto &d : dir) {
                int x = p.first + d[0];
                int y = p.second + d[1];
                int cur_id = n * x + y;
                if (x < 0 || x >= m || y < 0 || y >= n 
                		|| roots[cur_id] == -1) {
                    continue;
                }
                int father = findRoot(roots, cur_id);
                if (father != id) {
                    count--;
                    roots[id] = father;
                    id = father;
                }
            }
            res.push_back(count);
        }
        return res;
    }
    
    int findRoot(vector<int> &roots, int id) {
        while (roots[id] != id) {
            roots[id] = roots[roots[id]];
            id = roots[id];
        }
        return id;
    }
};