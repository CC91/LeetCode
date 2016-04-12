// 206. Reverse Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // recursion
    ListNode* reverseList(ListNode* head) {
        if (!head ||!head->next) return head;
        ListNode *res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
};


class Solution {
public: // iteration
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL;
        while (head) {
            ListNode *tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};