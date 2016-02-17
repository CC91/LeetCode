// 108. Convert Sorted Array to Binary Search Tree

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
public: // DFS
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(nums, 0, nums.size()-1);
    }
    
    TreeNode* dfs(vector<int>& nums, int start, int end) {
        if (start>end) return NULL; // base case
        int mid = (start+end)>>1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = dfs(nums, start, mid-1);
        root->right = dfs(nums, mid+1, end);
        return root;
    }
};