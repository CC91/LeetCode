// 36. Valid Sudoku

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size()!=9 ||board[0].size()!=9) return false;
        // check col & row
        for (int i=0; i<9; i++) {
            vector<bool> colVisited(9, false);
            vector<bool> rowVisited(9, false);
            for (int j=0; j<9; j++) {
                if (board[i][j]!='.') {
                    int t = board[i][j]-'0';
                    if (colVisited[t]) return false;
                    else colVisited[t] = true;
                }
                if (board[j][i]!='.') {
                    int t = board[j][i]-'0';
                    if (rowVisited[t]) return false;
                    else rowVisited[t] = true;
                }
            }
        }
        // check each sub box
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                int a = 3*i, b = 3*j;
                vector<bool> subVisited(9, false);
                for (int m=a; m<a+3; m++) {
                    for (int n=b; n<b+3; n++) {
                        if (board[m][n]!='.') {
                            int t = board[m][n]-'0';
                            if (subVisited[t]) return false;
                            else subVisited[t] = true;
                        }
                    }
                }
            }
        }
        return true;
    }
};