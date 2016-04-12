// 234. Palindrome Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // reverse the second half and compare with the first half
    bool isPalindrome(ListNode* head) {
        if (!head ||!head->next) return true;
        ListNode *s = head, *f = head;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
        }
        ListNode *last = s->next, *pre = NULL;
        while (last) {
            ListNode *tmp = last->next;
            last->next = pre;
            pre = last;
            last = tmp;
        }
        while (pre) {
            if (head->val!=pre->val) return false;
            pre = pre->next;
            head = head->next;
        }
        return true;
    }
};


class Solution {
public: // stack
    bool isPalindrome(ListNode* head) {
        if (!head ||!head->next) return true;
        stack<int> stk;
        stk.push(head->val);
        ListNode *s = head, *f = head;
        while (f->next && f->next->next) {
            s = s->next;
            f = f->next->next;
            stk.push(s->val);
        }
        if (!f->next) stk.pop(); // odd number list
        while (s->next) {
            s = s->next;
            int tmp = stk.top();
            stk.pop();
            if (tmp!=s->val) return false;
        }
        return true;
    }
};