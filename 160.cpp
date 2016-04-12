// 160. Intersection of Two Linked Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // 2 pointers 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA ||!headB) return NULL;
        ListNode *p1 = headA, *p2 = headB;
        while (p1 && p2) {
            if (p1 == p2) return p1;
            p1 = p1->next;
            p2 = p2->next;
            if (!p1 && !p2) return NULL;
            if (!p1) p1 = headB;
            if (!p2) p2 = headA;
        }
        return NULL;
    }
};


class Solution {
public: 
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA ||!headB) return NULL;
        int la = 0, lb = 0;
        ListNode *pa = headA, *pb = headB;
        while (pa) {
            pa = pa->next;
            la++;
        }
        while (pb) {
            pb = pb->next;
            lb++;
        }
        if (pa!=pb) return NULL;
        while (la>lb) {
            headA = headA->next;
            la--;
        }
        while (la<lb) {
            headB = headB->next;
            lb--;
        }
        while (headA!=headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};