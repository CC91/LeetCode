// 25. Reverse Nodes in k-Group

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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return NULL;
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        ListNode* q=p;
        while (1) {
            int i = 0;
            while (q && i<k) {
                q = q->next;
                i++;
            }
            if (!q) return head->next;
            while (p->next!=q) {
                ListNode* t1 = p->next;
                ListNode *t2 = q->next;
                p->next = t1->next;
                q->next = t1;
                t1->next = t2;
            }
            for (int j=0; j<k; j++) p = p->next;
            q = p;
        }
        return head->next;
    }
};