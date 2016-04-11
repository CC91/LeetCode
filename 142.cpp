// 142. Linked List Cycle II

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // 2 pointers, https://leetcode.com/problems/linked-list-cycle/
    ListNode *detectCycle(ListNode *head) {
        if (!head) return NULL;
        ListNode *s = head, *f = head;
        do {
            if (!f->next ||!f->next->next) return NULL;
            s = s->next;
            f = f->next->next;
        } while (s!=f);
        s = head;
        while (s!=f) {
            s = s->next;
            f = f->next;
        }
        return s;
    }
};