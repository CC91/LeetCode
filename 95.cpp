// 95. Unique Binary Search Trees II

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
    vector<TreeNode*> generateTrees(int n) {
        if (n==0) return {}; // corner case
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int MIN, int MAX) {
        vector<TreeNode*> res;
        if (MIN>MAX) {
            res.push_back(NULL); // need to push null pointer which means no child
            return res;
        }
        for (int i=MIN; i<=MAX; i++) {
            vector<TreeNode*> leftTree = helper(MIN, i-1);
            vector<TreeNode*> rightTree = helper(i+1, MAX);
            for (auto j:leftTree) {
                for (auto k:rightTree) {
                    TreeNode* root = new TreeNode(i); // i is the root
                    root->left = j;
                    root->right = k;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};