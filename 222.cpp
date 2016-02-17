// 222. Count Complete Tree Nodes

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
public: // recursion, compute the number of complete BT then add the number of non-complete BT
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        TreeNode *l = root, *r = root;
        int hl = 0, hr = 0;
        while (l) {
            hl++;
            l = l->left;
        }
        while (r) {
            hr++;
            r = r->right;
        }
        if (hl==hr) return (1<<hl)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};


class Solution { // http://bookshadow.com/weblog/2015/06/06/leetcode-count-complete-tree-nodes/
public: // set the levels of the tree from top to bottom as lv0~lv(depth-1)
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int depth = 0;
        TreeNode* n = root;
        while (n) {
            depth++;
            n = n->left;
        }
        int left = 0, right = (1<<(depth-1))-1; // depth-1 is complete BT
        while (left<=right) {
            int mid = (left+right)>>1;
            if (getNode(root, mid, depth-1)) left = mid+1; // notice the depth
            else right = mid-1;
        }
        return (1<<(depth-1))+right;
    }
    
    TreeNode* getNode(TreeNode* root, int mid, int depth) {
        if (!root) return NULL;
        while (depth-- && root) {
            if (mid & (1<<depth)) root = root->right; // left child is set as 0, right as 1
            else root = root->left;
        }
        return root;
    }
};
