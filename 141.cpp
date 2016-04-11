// 141. Linked List Cycle

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // 2 pointers, slow and fast
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        ListNode *s = head, *f = head;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
            if (s==f) return true;
        }
        return false;
    }
};