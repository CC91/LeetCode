// 298. Binary Tree Longest Consecutive Sequence

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
    int longestConsecutive(TreeNode* root) {
        return helper(root, NULL, 0);
    }
    
    int helper(TreeNode* n, TreeNode* parent, int len) {
        if (!n) {
            return len;
        }
        len = (parent && parent -> val + 1 == n -> val) ? len + 1 : 1;
        return max(len, max(helper(n -> left, n, len), helper(n -> right, n, len)));
    }
};