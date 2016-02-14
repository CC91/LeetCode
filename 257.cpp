// 257. Binary Tree Paths

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        string tmp;
        dfs(root, tmp, res);
        return res;
    }
    
    void dfs(TreeNode* root, string tmp, vector<string> &res) {
        if (!root) return;
        if (!tmp.empty()) tmp+="->"+to_string(root->val);
        else tmp = to_string(root->val);
        if (root->left ||root->right) {
            dfs(root->left, tmp, res);
            dfs(root->right, tmp, res);
        }
        else res.push_back(tmp);
    }
};


class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (!root) return res;
        dfs(root, to_string(root->val), res);
        return res;
    }
    
    void dfs(TreeNode* root, string path, vector<string> &res) {
        if (!root) return;
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        if (root->left) dfs(root->left, path+"->"+to_string(root->left->val), res);
        if (root->right) dfs(root->right, path+"->"+to_string(root->right->val), res);
    }
};