// 230. Kth Smallest Element in a BST

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
public: // dfs
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        dfs(root, k, res);
        return res;
    }
    
    void dfs(TreeNode* root, int &k, int &res) {
        if (!root ||!k) return; // base case, not just !root case
        dfs(root->left, k, res); // Use the property of a BST: left->root->right, it is increasing, so we start traversing from left tree
        if(--k==0) {
            res = root->val;
            return;
        }
        dfs(root->right, k, res);
    }
};