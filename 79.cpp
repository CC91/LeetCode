// 79. Word Search

class Solution {
public: // backtracking with bool vector
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (dfs(board, word, i, j, 0, visited)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string &word, int i, int j, int idx, vector<vector<bool>> &visited) {
        if (idx==word.size()) return true; // base case
        int m = board.size(), n = board[0].size();
        if (i<0 ||j<0 ||i>=m ||j>=n ||board[i][j]!=word[idx] ||visited[i][j]) return false;
        visited[i][j] = true;
        if (dfs(board, word, i+1, j, idx+1, visited) ||dfs(board, word, i-1, j, idx+1, visited) ||dfs(board, word, i, j+1, idx+1, visited) ||dfs(board, word, i, j-1, idx+1, visited)) return true;
        visited[i][j] = false; // backtracking
        return false;
    }
};


class Solution {
public: // backtracking without boolean
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (dfs(board, word, i, j)) return true;
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string &word, int i, int j) {
        int m = board.size(), n = board[0].size();
        if (word.size()==0) return true;
        if (i<0 ||j<0 ||i>=m ||j>=n ||board[i][j]!=word[0]) return false;
        char c = board[i][j];
        board[i][j] = '*';
        string s = word.substr(1);
        if (dfs(board, s, i+1, j) ||dfs(board, s, i-1, j) ||dfs(board, s, i, j+1) ||dfs(board, s, i, j-1)) return true;
        board[i][j] = c;
        return false;
    }
};