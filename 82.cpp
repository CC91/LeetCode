// 82. Remove Duplicates from Sorted List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // keep a pre behind the cur
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *pre = dummy, *cur = head;
        dummy->next = head;
        bool duplicate = false;
        while (cur) {
            if (cur->next && cur->val==cur->next->val) {
                ListNode *tmp = cur->next;
                cur->next = tmp->next;
                duplicate = true;
            } else if (duplicate) {
                pre->next = cur->next;
                cur = cur->next;
                duplicate = false;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};