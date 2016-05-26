// 208. Implement Trie (Prefix Tree)

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        val = 0;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
    int val;
    TrieNode *children[26];
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
        count = 0;
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            int index = word[i] - 'a';
            if (!p -> children[index]) {
                p -> children[index] = new TrieNode();
            }
            p = p -> children[index];
        }
        count++;
        p -> val = count;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        int n = word.size();
        for (int i = 0; i < n; i++) {
            int index = word[i] - 'a';
            if (p -> children[index]) {
                p = p -> children[index];
            } else {
                return false;
            }
        }
        if (p -> val != 0) {
            return true;
        } else {
            return false;
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        int n = prefix.size();
        for (int i = 0; i < n; i++) {
            int index = prefix[i] - 'a';
            if (p -> children[index]) {
                p = p -> children[index];
            } else {
                return false;
            }
        }
        return true;
    }

private:
    TrieNode* root;
    int count;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");