// 366. Find Leaves of Binary Tree

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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        helper(root, res);
        return res;
    }
    
    int helper(TreeNode* root, vector<vector<int>> &res) {
        if (!root) {
            return 0;
        }
        int height = 1 + max(helper(root -> left, res), helper(root -> right, res));
        if (height > res.size()) {
            res.push_back(vector<int> ());
        }
        res[height - 1].push_back(root -> val);
        return height;
    }
};


class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root) {
            vector<int> tmp;
            root = helper(root, tmp);
            res.push_back(tmp);
        }
        return res;
    }
    
    TreeNode* helper(TreeNode* root, vector<int> &res) {
        if (!root) {
            return NULL;
        }
        if (!root -> left && !root -> right) {
            res.push_back(root -> val);
            return NULL;
        }
        root -> left = helper(root -> left, res);
        root -> right = helper(root -> right, res);
        return root;
    }
};