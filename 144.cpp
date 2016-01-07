// 144. Binary Tree Preorder Traversal

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    
    void helper(TreeNode* root, vector<int> &res) {
        if (!root) return;
        res.push_back(root->val);
        helper(root->left, res);
        helper(root->right, res);
    }
};


class Solution {
public:// use a stack to store right nodes
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* n = root;
        stack<TreeNode*> s;
        while (n ||!s.empty()) {
            if (!n) {
                n = s.top();
                s.pop();
            }
            res.push_back(n->val);
            if (n->right) s.push(n->right);
            n = n->left;
        }
        return res;
    }
};