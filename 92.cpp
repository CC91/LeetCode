// 92. Reverse Linked List II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // reverse the m~n nodes
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;
        for (int i=0; i<m-1; i++) head = head->next;
        ListNode *pre = head->next, *cur = pre->next;
        for (int i=0; i<n-m; i++) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        head->next->next = cur;
        head->next = pre;
        return dummy->next;
    }
};