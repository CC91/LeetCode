// 173. Binary Search Tree Iterator

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator { // use aSTACK to store all the left children and of the tree
    stack<TreeNode*> s;
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            s.push(root);
            root = root->left; // since it is a BST, stack can always keep the smallest node at the top
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* n = s.top(); // n is the smallest node we want, but we need to keep track of the next smallest node after we pop node n
        s.pop();
        TreeNode* r = n->right; // n might have right child which is the smallest node after n
        while (r) {
            s.push(r);
            r = r->left;
        }
        return n->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */