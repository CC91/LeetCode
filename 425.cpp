// 425. Word Squares

class Solution {
public:
    struct TrieNode {
        TrieNode *child[26];
        vector<int> indices;
        TrieNode () {
            for (auto &a : child) {
                a = NULL;
            }
        }
    };
    
    struct Trie {
        TrieNode *root;
        Trie () : root (new TrieNode()){}
        void buildTrie(vector<string>& words) {
            for (int i = 0; i < words.size(); i++) {
                TrieNode *p = root;
                for (int j = 0; j < words[i].size(); j++) {
                    int t = words[i][j] - 'a';
                    if (!p -> child[t]) {
                        p -> child[t] = new TrieNode();
                    }
                    p = p -> child[t];
                    p -> indices.push_back(i);
                }
            }
        }
    };
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        vector<vector<string>> res;
        vector<string> tmp(words[0].size());
        Trie T;
        T.buildTrie(words);
        for (auto a : words) {
           tmp[0] = a; 
           helper(words, 1, T.root, tmp, res);
        }
        return res;
    }
    
    void helper(vector<string>& words, int len, TrieNode *root, 
        vector<string> &tmp, vector<vector<string>> &res) {
        if (len == words[0].size()) {
            res.push_back(tmp);
            return;
        }
        string s = "";
        for (int i = 0; i < len; i++) {
            s += tmp[i][len];
        }
        TrieNode *p = root;
        for (int i = 0; i < s.size(); i++) {
            int t = s[i] - 'a';
            if (!p -> child[t]) {
                return;
            }
            p = p -> child[t];
        }
        for (int idx : p -> indices) {
            tmp[len] = words[idx];
            helper(words, len + 1, root, tmp, res);
        }
    }
};