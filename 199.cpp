// 199. Binary Tree Right Side View

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
public: // use 2 queues to store current level and next level, similar to level traversal
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode*> curL, nextL;
        curL.push(root);
        int n = 0;
        while (1) {
            while (!curL.empty()) {
                TreeNode* cur = curL.front();
                curL.pop();
                n = cur->val;
                if (cur->left) nextL.push(cur->left);
                if (cur->right) nextL.push(cur->right);
            }
            res.push_back(n); // when curL is empty, it means n is the rightmost node value on that level
            swap(curL, nextL);
            if (curL.empty()) return res;
        }
    }
};