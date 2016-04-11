// 143. Reorder List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // reverse the second half and insert nodes in it to the first half
    void reorderList(ListNode* head) {
        if (!head ||!head->next) return;
        ListNode *s = head, *f = head;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode *last = s->next; // the tail node of the reversed second half
        ListNode *pre = NULL;
        while (last) { // reverse the second half
            ListNode *tmp = last->next;
            last->next = pre;
            pre = last;
            last = tmp;
        }
        s->next = NULL; // the last node in the reversed final list
        while (pre && head) {
            ListNode *pos = head->next;
            head->next = pre;
            pre = pre->next;
            head->next->next = pos;
            head = pos;
        }
    }
};