// 114. Flatten Binary Tree to Linked List

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
public: // like a preorder traversal
    void flatten(TreeNode* root) {
        if (!root) return;
        TreeNode* flat = root;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
            if (cur!=root) {
                flat->left = NULL;
                flat->right = cur;
                flat = flat->right;
            }
        }
    }
};