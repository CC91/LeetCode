// 437. Path Sum III

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
    int pathSum(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        return helper(root, sum) + pathSum(root -> left, sum) 
        	+ pathSum(root -> right, sum);
    }
    
    int helper(TreeNode* root, int sum) {
        if (!root) {
            return 0;
        }
        return (root -> val == sum) + helper(root -> left, sum - root -> val)
        	+ helper(root -> right, sum - root -> val);
    }
};