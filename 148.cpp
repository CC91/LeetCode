// 148. Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // merge sort with recursion
    ListNode* sortList(ListNode* head) {
        if (!head ||!head->next) return head;
        ListNode *s = head, *f = head;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }
        f = s->next;
        s->next = NULL;
        ListNode *p1 = sortList(head), *p2 = sortList(f);
        return merge(p1, p2);
    }
    
    ListNode* merge(ListNode* p1, ListNode* p2) {
        if (!p1) return p2;
        else if (!p2) return p1;
        else if (!p1 && !p2) return NULL;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (p1 && p2) {
            if (p1->val<p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        } 
        p->next = p1?p1:p2;
        return dummy->next;
    }
};