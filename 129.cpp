// 129. Sum Root to Leaf Numbers

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
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        int res = 0;
        dfs(root, 0, res);
        return res;
    }
    
    void dfs(TreeNode* root, int n, int &res) {
        if (!root) return;
        n = n*10+root->val;
        if (!root->left && !root->right) res += n;
        if (root->left) dfs(root->left, n, res);
        if (root->right) dfs(root->right, n, res);
    }
};