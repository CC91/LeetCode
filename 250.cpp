// 250. Count Univalue Subtrees

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
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        helper(root, -1, res);
        return res;
    }
    
    bool helper(TreeNode* root, int val, int &res) {
        if (!root) {
            return true;
        }
        if (!helper(root -> left, root -> val, res) | !helper(root -> right, 
        	root -> val, res)) {
            return false;
        }
        res++;
        return root -> val == val;
    }
};