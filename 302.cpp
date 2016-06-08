// 302. Smallest Rectangle Enclosing Black Pixels

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty()) {
            return 0;
        }
        int m = image.size();
        int n = image[0].size();
        int left = INT_MAX;
        int right = INT_MIN;
        int up = INT_MAX;
        int down = INT_MIN;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (image[i][j] == '1') {
                    left = min(left, j);
                    right = max(right, j);
                    up = min(up, i);
                    down = max(down, i);
                }
            }
        }
        return (right - left + 1) * (down - up + 1);
    }
};



class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        if (image.empty()) {
            return 0;
        }
        int left = y;
        int right = y;
        int up = x;
        int down = x;
        helper(image, x, y, left, right, up, down);
        return (right - left + 1) * (down - up + 1);
    }
    
    void helper(vector<vector<char>>& image, int x, int y, int &left, int &right, int &up, int &down) {
        int m = image.size();
        int n = image[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || image[x][y] != '1') {
            return;
        }
        image[x][y] = '*';
        left = min(left, y);
        right = max(right, y);
        up = min(up, x);
        down = max(down, x);
        helper(image, x + 1, y, left, right, up, down);
        helper(image, x - 1, y, left, right, up, down);
        helper(image, x, y + 1, left, right, up, down);
        helper(image, x, y - 1, left, right, up, down);
    }
};



