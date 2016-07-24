// 369. Plus One Linked List

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
    ListNode* plusOne(ListNode* head) {
        if (!head) {
            return NULL;
        }
        ListNode *h = helper(head);
        ListNode *p = h;
        ListNode *pre = h;
        int carry = 1;
        while (p) {
            pre = p;
            int cur = p -> val + carry;
            p -> val = cur % 10;
            carry = cur / 10;
            if (carry == 0) {
                break;
            }
            p = p -> next;
        }
        if (carry) {
            pre -> next = new ListNode(1);
        }
        return helper(h);
    }
    
    ListNode* helper(ListNode* head) {
        if (!head || !head -> next) {
            return head;
        }
        ListNode *pre = NULL;
        while (head) {
            ListNode *t = head -> next;
            head -> next = pre;
            pre = head;
            head = t;
        }
        return pre;
    }
};


class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        if (!head) {
            return head;
        }
        int carry = helper(head);
        if (carry == 1) {
            ListNode *h = new ListNode(1);
            h -> next = head;
            return h;
        }
        return head;
    }
    
    int helper(ListNode *head) {
        if (!head) {
            return 1;
        }
        int carry = helper(head -> next);
        int t = head -> val + carry;
        head -> val = t % 10;
        carry = t / 10;
        return carry;
    }
};