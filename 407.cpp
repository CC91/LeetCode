// 407. Trapping Rain Water II

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.empty()) {
            return 0;
        }
        int m = heightMap.size();
        int n = heightMap[0].size();
        int res = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (0 == i || m - 1 == i || 0 == j || n - 1 == j) {
                    visited[i][j] = true;
                    q.push({-heightMap[i][j], {i, j}});
                }
            }
        }
        vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!q.empty()) {
            auto t = q.top();
            q.pop();
            int h = -t.first;
            int x = t.second.first;
            int y = t.second.second;
            for (auto a : dir) {
                int nx = x + a[0];
                int ny = y + a[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) {
                    continue;
                }
                if (heightMap[nx][ny] < h) {
                    res += (h - heightMap[nx][ny]);
                    heightMap[nx][ny] = h;
                }
                visited[nx][ny] = true;
                q.push({-heightMap[nx][ny], {nx, ny}});
            }
        }
        return res;
    }
};