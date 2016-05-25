// 337. House Robber III

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
public: // DFS
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return helper(root, m);
    }
    
    int helper(TreeNode* root, unordered_map<TreeNode*, int> &m) {
        if (!root) {
            return 0;
        }
        if (m.count(root)) {
            return m[root];
        }
        int res = 0;
        if (root -> left) {
            res += helper(root -> left -> left, m) + helper(root -> left -> right, m);
        }
        if (root -> right) {
            res += helper(root -> right -> left, m) + helper(root -> right -> right, m);
        }
        res = max(res + root -> val, helper(root -> left, m) + helper(root -> right, m));
        m[root] = res;
        return res;
    }
};



class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = helper(root);
        return max(res[0], res[1]);
    }
    
    vector<int> helper(TreeNode* root) {
        vector<int> res(2, 0);
        if (!root) {
            return res;
        }
        vector<int> l = helper(root -> left);
        vector<int> r = helper(root -> right);
        res[0] = max(l[0], l[1]) + max(r[0], r[1]);
        res[1] = l[0] + r[0] + root -> val;
        return res;
    }
};