// 86. Partition List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // scan the list and copy to a new list. 2 lists, one for copying smaller values the other recording larger values.
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = new ListNode(0), *h2 = new ListNode(0);
        ListNode *p1 = h1, *p2 = h2;
        while (head) {
            if (head->val<x) {
                p1->next = head;
                p1 = p1->next;
            } else {
                p2->next = head;
                p2 = p2->next;
            }
            head = head->next;
        }
        p2->next = NULL;
        p1->next = h2->next;
        return h1->next;
    }
};