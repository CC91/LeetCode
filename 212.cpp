// 212. Word Search II

class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        string str;
        TrieNode () : str("") {
            for (auto &a : child) {
                a = NULL;
            }
        }
    };
    
    struct Trie {
        TrieNode *root;
        Trie () : root (new TrieNode()) {}
        void insert(string s) {
            TrieNode *p = root;
            for (auto &a : s) {
                int i = a - 'a';
                if (!p -> child[i]) {
                    p -> child[i] = new TrieNode();
                }
                p = p -> child[i];
            }
            p -> str = s;
        }
    };
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || words.empty()) {
            return res;
        }
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        Trie T;
        for (auto &a : words) {
            T.insert(a);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (T.root -> child[board[i][j] - 'a']) {
                    search(board, T.root -> child[board[i][j] - 'a'], i, j, visited, res);
                }
            }
        }
        return res;
    }
    
    void search(vector<vector<char>>& board, TrieNode *p, int i, int j, 
        vector<vector<bool>> &visited, vector<string> &res) {
            if (!p -> str.empty()) {
                res.push_back(p -> str);
                p -> str.clear();
            }
            visited[i][j] = true;
            int m = board.size();
            int n = board[0].size();
            int d[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
            for (auto &a : d) {
                int x = a[0] + i;
                int y = a[1] + j;
                if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y] 
                    && p -> child[board[x][y] - 'a']) {
                    search(board, p -> child[board[x][y] - 'a'], x, y, visited, res);
                }
            }
            visited[i][j] = false;
        }
};