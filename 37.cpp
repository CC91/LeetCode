// 37. Sudoku Solver

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
    
    bool solver(vector<vector<char>>& board) { // scan the board
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if (board[i][j]=='.') {
                    for (char num='1'; num<='9'; num++) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;
                            if (solver(board)) return true;
                            else board[i][j] = '.'; // reset the grid
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int i, int j, char val) {
        for (int r=0; r<9; r++) { // check big grid
            if (board[r][j]==val) return false;
        }
        for (int c=0; c<9; c++) {
            if (board[i][c]==val) return false;
        }
        for (int r=i/3*3; r<i/3*3+3; r++) { // check sub grid
            for (int c=j/3*3; c<j/3*3+3; c++) {
                if (board[r][c]==val) return false;
            }
        }
        return true;
    }
};