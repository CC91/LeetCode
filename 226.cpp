// 226. Invert Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            root->left = invertTree(root->left);
            root->right = invertTree(root->right);
            TreeNode* tmp = root->left;
            root->left = root->right;
            root->right = tmp;
        }
        return root;
    }
};


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root) {
            TreeNode* tmp = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(tmp);
        }
        return root;
    }
};


class Solution {
public: // iteration
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return NULL;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* n = q.front();
            q.pop();
            TreeNode* tmp = n->left;
            n->left = n->right;
            n->right = tmp;
            if (n->left) q.push(n->left);
            if (n->right) q.push(n->right);
        }
        return root;
    }
};