// 445. Add Two Numbers II

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return !l1 ? l2 : l1;
        }
        ListNode *t1 = helper(l1);
        ListNode *t2 = helper(l2);
        int c = 0;
        ListNode *dummy = new ListNode(0);
        ListNode *p = dummy;
        while (t1 || t2 || c) {
            if (t1) {
                c += t1 -> val;
                t1 = t1 -> next; 
            }
            if (t2) {
                c += t2 -> val;
                t2 = t2 -> next;
            }
            p -> next = new ListNode(c % 10);
            c /= 10;
            p = p -> next;
        }
        return helper(dummy -> next);
    }
    
    ListNode *helper(ListNode* l) {
        if (!l || !l -> next) {
            return l;
        }
        ListNode *pre = NULL;
        while (l) {
            ListNode *t = l -> next;
            l -> next = pre;
            pre = l;
            l = t;
        }
        return pre;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1 || !l2) {
            return !l1 ? l2 : l1;
        }
        stack<int> s1;
        stack<int> s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int cur = 0;
        ListNode *head = NULL;
        while (!s1.empty() || !s2.empty() || cur) {
            if (!s1.empty()) {
                cur += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                cur += s2.top();
                s2.pop();
            }
            ListNode *t = new ListNode(cur % 10);
            t -> next = head;
            head = t;
            cur /= 10;
        }
        return head;
    }
};