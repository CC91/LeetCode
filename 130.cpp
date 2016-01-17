// 130. Surrounded Regions

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.size()<3 ||board[0].size()<3) return;
        border(board, 'O', 'Y');
        replace(board, 'O', 'X');
        border(board, 'Y', 'O');
    }
    
    void fill(vector<vector<char>>& board, int i, int j, char c1, char c2) {
        int m = board.size(), n = board[0].size();
        if (i<0 ||i>=m ||j<0 ||j>=n ||board[i][j]!=c1) return;
        stack<pair<int, int>> s;
        s.push(make_pair(i, j));
        
        while (!s.empty()) {
            i = s.top().first;
            j = s.top().second;
            s.pop();
            board[i][j] = c2;
            if (i>0 && board[i-1][j]==c1) s.push(make_pair(i-1, j));
            if (i<m-1 && board[i+1][j]==c1) s.push(make_pair(i+1, j));
            if (j>0 && board[i][j-1]==c1) s.push(make_pair(i, j-1));
            if (j<n-1 && board[i][j+1]==c1) s.push(make_pair(i, j+1));
        }
    }
    
    void border(vector<vector<char>>& board, char c1, char c2) {
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++) {
            if (board[i][0]==c1) fill(board, i, 0, c1, c2);
            if (board[i][n-1]==c1) fill(board, i, n-1, c1, c2);
        }
        
        for (int j=1; j<n-1; j++) {
            if (board[0][j]==c1) fill(board, 0, j, c1, c2);
            if (board[m-1][j]==c1) fill(board, m-1, j, c1, c2);
        }
    }
    
    void replace(vector<vector<char>>& board, char c1, char c2) {
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j]==c1) board[i][j]=c2;
            }
        }
    }
};