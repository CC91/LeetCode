// 289. Game of Life

class Solution {
public: // status 0: d-d, 1: l-l, 2: l-d, 3: d-l
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<int> dx{-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy{-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int cnt = 0;
                for (int k=0; k<8; k++) {
                    int x = i+dx[k], y = j+dy[k];
                    if (x>=0 && x<m && y>=0 && y<n &&(board[x][y]==1 ||board[x][y]==2)) cnt++;
                }
                if (board[i][j] && (cnt<2 ||cnt>3)) board[i][j] = 2;
                else if(!board[i][j] && cnt==3) board[i][j] = 3;
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) board[i][j] %= 2;
        }
    }
};