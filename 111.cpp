// 111. Minimum Depth of Binary Tree

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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 1));
        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            if (!cur.first->left && !cur.first->right) return cur.second;
            if (cur.first->left) q.push(make_pair(cur.first->left, cur.second+1));
            if (cur.first->right) q.push(make_pair(cur.first->right, cur.second+1));
        }
    }
};