// 83. Remove Duplicates from Sorted List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;
        ListNode *pre = head, *p = head->next;
        while (p) {
            if (pre->val==p->val) {
                p = p->next;
                pre->next = p;
                continue;
            }
            pre = pre->next;
            p = p->next;
        }
        return head;
    }
};