// 156. Binary Tree Upside Down

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
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        TreeNode *cur = root;
        TreeNode *pre = NULL;
        TreeNode *next = NULL;
        TreeNode *preRightNode = NULL;
        while (cur) {
            next = cur -> left;
            cur -> left = preRightNode;
            preRightNode = cur -> right;
            cur -> right = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
 
 
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root -> left) {
            return root;
        }
        TreeNode *l = root -> left;
        TreeNode *r = root -> right;
        TreeNode *newRoot = upsideDownBinaryTree(l);
        l -> left = r;
        l -> right = root;
        root -> left = NULL;
        root -> right = NULL;
        return newRoot;
    }
};