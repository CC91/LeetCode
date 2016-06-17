// 270. Closest Binary Search Tree Value 

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
    int closestValue(TreeNode* root, double target) {
        int res = root -> val;
        if (target < root -> val && root -> left) {
            int l = closestValue(root -> left, target);
            if (abs(res - target) >= abs(l - target)) {
                res = l;
            }
        } else if (target > root -> val && root -> right) {
            int r = closestValue(root -> right, target);
            if (abs(res - target) >= abs(r - target)) {
                res = r;
            }
        }
        return res;
    }
};



class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int a = root -> val;
        TreeNode *t = target < a ? root -> left : root -> right;
        if (!t) {
            return a;
        }
        int b = closestValue(t, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};



class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        int res = root -> val;
        while (root) {
            if (abs(res - target) >= abs(root -> val - target)) {
                res = root -> val;
            }
            root = target < root -> val ? root -> left : root -> right;
        }
        return res;
    }
};