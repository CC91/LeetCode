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


class Solution {
public: // 2 pointers
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head ||!head->next ||!k) return head;
        int len = 1;
        ListNode *p = head, *slow = head, *fast = head;
        while (p->next) {
            len++;
            p = p->next;
        }
        k = k%len; // if k==len, there would be no rotation
        while (k--) {
            fast = fast->next;
        }
        if (!fast ||fast==head) return head; // when k==0, fast==NULL
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *newHead = slow->next;
        fast->next = head;
        slow->next = NULL;
        return newHead;
    }
};

