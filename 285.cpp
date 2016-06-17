// 285. Inorder Successor in BST

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* res = NULL;
        while (root) {
            if (root -> val > p -> val) {
                res = root;
                root = root -> left;
            } else {
                root = root -> right;
            }
        }
        return res;
    }
};


class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root) {
            return NULL;
        }
        if (root -> val <= p -> val) {
            return inorderSuccessor(root -> right, p);
        } else {
            TreeNode* leftNode = inorderSuccessor(root -> left, p);
            return leftNode? leftNode : root;
        }
    }
};