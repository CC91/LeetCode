// 419. Battleships in a Board

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) {
            return 0;
        }
        int res = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    if (i > 0 && board[i - 1][j] == 'X') {
                        continue;
                    }
                    if (j > 0 && board[i][j - 1] == 'X') {
                        continue;
                    }
                    res++;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.empty()) {
            return 0;
        }
        int res = 0;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    helper(board, i, j);
                    res++;
                }
            }
        }
        return res;
    }
    
    void helper(vector<vector<char>>& board, int i, int j) {
        int m = board.size();
        int n = board[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'X') {
            return;
        }
        board[i][j] = '*';
        helper(board, i + 1, j);
        helper(board, i - 1, j);
        helper(board, i, j + 1);
        helper(board, i, j - 1);
    }
};


