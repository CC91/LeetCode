// 333. Largest BST Subtree

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
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        helper(root, res);
        return res;
    }
    
    void helper(TreeNode* root, int &res) {
        if (!root) {
            return;
        }
        int tmp = countNode(root, INT_MIN, INT_MAX);
        if (tmp != -1) {
            res = max(res, tmp);
            return;
        }
        helper(root -> left, res);
        helper(root -> right, res);
    }
    
    int countNode(TreeNode* root, int a, int b) {
        if (!root) {
            return 0;
        }
        if (root -> val <= a || root -> val >= b) {
            return -1;
        }
        int left = countNode(root -> left, a, root -> val);
        if (left == -1) {
            return -1;
        }
        int right = countNode(root -> right, root -> val, b);
        if (right == -1) {
            return -1;
        }
        return left + right + 1;
    }
};



class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int res = 0;
        int mini = INT_MIN;
        int maxi = INT_MAX;
        helper(root, mini, maxi, res);
        return res;
    }
    
    bool helper(TreeNode* root, int &mini, int &maxi, int &res) {
        if (!root) {
            return true;
        }
        int leftNodes = 0;
        int rightNodes = 0;
        int left_mini = INT_MIN;
        int left_maxi = INT_MAX;
        int right_mini = INT_MIN;
        int right_maxi = INT_MAX;
        bool left = helper(root -> left, left_mini, left_maxi, leftNodes);
        bool right = helper(root -> right, right_mini, right_maxi, rightNodes);
        if (left && right) {
            if ((!root -> left || root -> val > left_maxi) && (!root -> right || root -> val < right_mini)) {
                res = leftNodes + rightNodes + 1;
                mini = root -> left ? left_mini : root -> val;
                maxi = root -> right ? right_maxi : root -> val;
                return true;
            }
        }
        res = max(leftNodes, rightNodes);
        return false;
    }
};