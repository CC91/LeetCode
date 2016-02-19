// 116. Populating Next Right Pointers in Each Node 

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public: // BFS iteration
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *pre = NULL, *levelStart = NULL;
            for (; root; root = root->next) {
                if (!levelStart) levelStart = root->left?root->left:root->right;
                if (root->left) {
                    if (pre) pre->next = root->left;
                    pre = root->left;
                }
                if (root->right) {
                    if (pre) pre->next = root->right;
                    pre = root->right;
                }
            }
            root = levelStart;
        }
    }
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        TreeLinkNode *nodeNext = NULL, *rootNext = root->next;
        while (rootNext) { // get next child node 
            if (rootNext->left) {
                nodeNext = rootNext->left;
                break;
            }
            if (rootNext->right) {
                nodeNext = rootNext->right;
                break;
            }
            rootNext = rootNext->next;
        }
        if (root->right) root->right->next = nodeNext;
        if (root->left) root->left->next = root->right;
        connect(root->right);
        connect(root->left);
    }
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        dfs(root);
    }
    
    void dfs(TreeLinkNode *root) {
        if (!root->left) return;
        root->left->next = root->right;
        root->right->next = root->next==NULL?NULL:root->next->left;
        dfs(root->left);
        dfs(root->right);
    }
};


