// 145. Binary Tree Postorder Traversal

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    
    void helper(TreeNode* root, vector<int> &res) {
        if (!root) return;
        helper(root->left, res);
        helper(root->right, res);
        res.push_back(root->val);
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* child = root;
        while (!s.empty()) {
            TreeNode* cur = s.top();
            if ((!cur->left && !cur->right) ||cur->left==child ||cur->right==child) {
                res.push_back(cur->val);
                s.pop();
                child = cur;
            } else {
                if (cur->right) s.push(cur->right);
                if (cur->left) s.push(cur->left);
            }
        }
        return res;
    }
};