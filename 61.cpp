// 61. Rotate List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // get list length, k maybe > length
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head ||!head->next ||!k) return head;
        int len = 1;
        ListNode *p = head;
        while (p->next) {
            p = p->next;
            len++;
        }
        p->next = head;
        k = len-k%len;
        while (k--) {
            p = p->next;
        }
        head = p->next;
        p->next = NULL;
        return head;
    }
};