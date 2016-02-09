// 102. Binary Tree Level Order Traversal

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
public: // 2 queues
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> tmp;
        queue<TreeNode*> curL, nextL;
        curL.push(root);
        while (!curL.empty()) {
            TreeNode* curNode = curL.front();
            curL.pop();
            if (curNode) {
                tmp.push_back(curNode->val);
                nextL.push(curNode->left);
                nextL.push(curNode->right);
            }
            if (curL.empty()) {
                if (!tmp.empty()) res.push_back(tmp);
                tmp.clear();
                swap(curL, nextL);
            }
        }
        return res;
    }
};