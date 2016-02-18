// 105. Construct Binary Tree from Preorder and Inorder Traversal

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()!=inorder.size()) return NULL;
        return dfs(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int s1, int e1, int s2, int e2) {
        if (s1>e1 ||s2>e2) return NULL;
        TreeNode* root = new TreeNode(preorder[s1]);
        int rootIdx;
        for (int i=s2; i<=e2; i++) {
            if (inorder[i]==root->val) {
                rootIdx = i;
                break;
            }
        }
        int l = rootIdx-s2, r = e2-rootIdx; // length of the left subtree and right subtree
        root->left = dfs(preorder, inorder, s1+1, s1+l, s2, rootIdx-1);
        root->right = dfs(preorder, inorder, e1-r+1, e1, rootIdx+1, e2);
        return root; 
    }
};