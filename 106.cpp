// 106. Construct Binary Tree from Inorder and Postorder Traversal

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size()!=postorder.size()) return NULL;
        return dfs(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }
    
    TreeNode* dfs(vector<int>& inorder, vector<int>& postorder, int s1, int e1, int s2, int e2) {
        if (s1>e1 ||s2>e2) return NULL;
        TreeNode* root = new TreeNode(postorder[e2]);
        int rootIdx;
        for (int i=s1; i<=e1; i++) {
            if (inorder[i]==root->val) {
                rootIdx = i;
                break;
            }
        }
        int l = rootIdx-s1, r = e1-rootIdx;
        root->left = dfs(inorder, postorder, s1, rootIdx-1, s2, s2+l-1);
        root->right = dfs(inorder, postorder, rootIdx+1, e1, e2-r, e2-1);
        return root;
    }
};