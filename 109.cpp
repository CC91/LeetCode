// 109. Convert Sorted List to Binary Search Tree

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
public: // recursion, need to get the length of the list first
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *tmp = head;
        int n = 0;
        while (tmp) {
            n++;
            tmp = tmp->next;
        }
        return helper(head, 0, n-1);
    }
    
    TreeNode* helper(ListNode*& head, int start, int end) {
        if (start>end) return NULL;
        int mid = start+(end-start)/2;
        TreeNode *leftTree = helper(head, start, mid-1);
        TreeNode *root = new TreeNode(head->val);
        head = head->next;
        TreeNode *rightTree = helper(head, mid+1, end);
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
};