// 286. Walls and Gates

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) {
            return;
        }
        int m = rooms.size();
        int n = rooms[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    helper(rooms, i, j, 0);
                }
            }
        }
    }
    
    void helper(vector<vector<int>>& rooms, int i, int j, int d) {
        int m = rooms.size();
        int n = rooms[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || rooms[i][j] < d) {
            return;
        }
        rooms[i][j] = d;
        helper(rooms, i + 1, j, d + 1);
        helper(rooms, i - 1, j, d + 1);
        helper(rooms, i, j + 1, d + 1);
        helper(rooms, i, j - 1, d + 1);
    }
};


class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) {
            return;
        }
        int m = rooms.size();
        int n = rooms[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k = 0; k < 4; k++) {
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] < rooms[i][j] + 1) {
                    continue;
                }
                rooms[x][y] = rooms[i][j] + 1;
                q.push({x, y});
            }
        }
    }
};