// 348. Design Tic-Tac-Toe

class TicTacToe {
private:
    vector<vector<int>> board;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board.resize(n, vector<int> (n, 0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[row][col] = player;
        int i = 0;
        int j = 0;
        int N = board.size();
        for (i = 0; i < N; i++) { // check each row
            if (board[i][0] != 0) {
                for (j = 1; j < N; j++) {
                    if (board[i][j - 1] != board[i][j]) {
                        break;
                    }
                }
                if (j == N) {
                    return board[i][0];
                }
            }
        }
        for (j = 0; j < N; j++) { // check each column
            if (board[0][j] != 0) {
                for (i = 1; i < N; i++) {
                    if (board[i - 1][j] != board[i][j]) {
                        break;
                    }
                }
                if (i == N) {
                    return board[0][j];
                }
            }
        }
        if (board[0][0]) { // check diagonal
            for (i = 1; i < N; i++) {
                if (board[i][i] != board[0][0]) {
                    break;
                }
            }
            if (i == N) {
                return board[0][0];
            }
        }
        if (board[N - 1][0]) { // check anti_diagonal
            for (i = 1; i < N; i++) {
                if (board[N - 1 - i][i] != board[N - 1][0]) {
                    break;
                }
            }
            if (i == N) {
                return board[N - 1][0];
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */


 class TicTacToe {
private:
    vector<int> rows;
    vector<int> cols;
    int diagonal;
    int anti_diagonal;
    int N;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        N = n;
        rows.resize(n);
        cols.resize(n);
        diagonal = 0;
        anti_diagonal = 0;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        int count = (player == 1) ? 1 : -1;
        rows[row] += count;
        cols[col] += count;
        diagonal += (row == col) ? count : 0;
        anti_diagonal += (row == N - 1 - col) ? count : 0;
        return (abs(rows[row]) == N || abs(cols[col]) == N || abs(diagonal) == N || abs(anti_diagonal) == N) ? player : 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */