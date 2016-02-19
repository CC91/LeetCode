// 99. Recover Binary Search Tree

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
public: // http://yucoding.blogspot.com/2013/03/leetcode-question-75-recover-binary.html
    TreeNode *first, *second, *pre;
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        if (!pre) pre = root;
        if (pre->val>root->val) {
            if (!first) first = pre;
            second = root;
        }
        pre = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first = NULL, second = NULL, pre = NULL;
        inorder(root);
        int n = first->val;
        first->val = second->val;
        second->val = n;
        return;
    }
};