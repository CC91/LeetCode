// 124. Binary Tree Maximum Path Sum

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution { //http://bangbingsyb.blogspot.com/2014/11/leetcode-binary-tree-maximum-path-sum.html
public: // http://yucoding.blogspot.com/2012/12/leetcode-question-13-binary-tree.html
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, int &res) {
        if (!root) return 0;
        int max_l = dfs(root->left, res);
        int max_r = dfs(root->right, res); 
        int max_s = max(max(max_l, max_r)+root->val, root->val); // left or right subtree with current node
        int max_top = max(max(max_s, max_l+max_r+root->val), root->val); // left and right trees with current node
        res = max(res, max_top);
        return max_s; // pass max_s to let upper level compute the max_s and max_top
    }
};