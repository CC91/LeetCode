// 113. Path Sum II

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> tmp;
        helper(root, sum, tmp, res);
        return res;
    }
    
    void helper(TreeNode* root, int sum, vector<int> tmp, vector<vector<int>> &res) {
        if (!root) return;
        tmp.push_back(root->val);
        if (!root->left && !root->right && sum==root->val) res.push_back(tmp); // base case
        helper(root->left, sum-root->val, tmp, res);
        helper(root->right, sum-root->val, tmp, res);
    }
};