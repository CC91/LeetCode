// 101. Symmetric Tree

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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSym(root->left, root->right);
    }
    
    bool isSym(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true; // base case
        else if (!l ||!r ||l->val!=r->val) return false;
        return isSym(l->left, r->right) && isSym(l->right, r->left);
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> ql, qr;
        ql.push(root->left);
        qr.push(root->right);
        while (!ql.empty() && !qr.empty()) {
            TreeNode* l = ql.front();
            ql.pop();
            TreeNode* r = qr.front();
            qr.pop();
            if (!l &&!r) continue;
            else if (!l ||!r ||l->val!=r->val) return false;
            ql.push(l->left);
            ql.push(l->right);
            qr.push(r->right);
            qr.push(r->left);
        }
        if (!ql.empty() ||!qr.empty()) return false;
        return true;
    }
};