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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return Helper(root, prev);
    }
    
    bool Helper(TreeNode* root, TreeNode* &prev) {
        if (!root) return true;
        if (!Helper(root->left, prev)) return false;
        if (prev!=NULL && prev->val>=root->val) return false;
        prev = root;
        return Helper(root->right, prev);
    }
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return Helper(root, LONG_MIN, LONG_MAX);
    }
    
    bool Helper(TreeNode* root, long MIN, long MAX) {
        if (!root) return true;
        return root->val>MIN && root->val<MAX && Helper(root->left, MIN, root->val) && Helper(root->right, root->val, MAX);
    }
};