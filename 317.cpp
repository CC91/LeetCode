// 317. Shortest Distance from All Buildings

class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int res = INT_MAX;
        int val = 0;
        vector<vector<int>> sum = grid;
        vector<vector<int>> dir{{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = INT_MAX;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vector<vector<int>> dist = grid;
                    while (!q.empty()) {
                        int a = q.front().first;
                        int b = q.front().second;
                        q.pop();
                        for (int k = 0; k < dir.size(); k++) {
                            int x = a + dir[k][0];
                            int y = b + dir[k][1];
                            if (x >= 0 && x < m && y >=0 && y < n && grid[x][y] == val) {
                                --grid[x][y];
                                q.push({x, y});
                                dist[x][y] = dist[a][b] + 1;
                                sum[x][y] += dist[x][y] - 1;
                                res = min(res, sum[x][y]);
                            }
                        }
                    }
                    --val;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};