// 103. Binary Tree Zigzag Level Order Traversal

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
public: // use 2 stacks to store current and next levels, and a flag to provide zigzag level traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        vector<int> tmp;
        stack<TreeNode*> curL, nextL;
        curL.push(root);
        bool flag = true;
        while (!curL.empty()) {
            TreeNode* cur = curL.top();
            curL.pop();
            if (cur) {
                tmp.push_back(cur->val);
                if (flag) {
                    nextL.push(cur->left);
                    nextL.push(cur->right);
                } else {
                    nextL.push(cur->right);
                    nextL.push(cur->left);
                }
            }
            if (curL.empty()) {
                if (!tmp.empty()) {
                    res.push_back(tmp);
                    tmp.clear();
                    swap(curL, nextL);
                    flag = !flag;
                }
            }
        }
        return res;
    }
};