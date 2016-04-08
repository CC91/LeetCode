// 23. Merge k Sorted Lists

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // D&Q, merge every 2 lists from both sides
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        int end = lists.size()-1;
        while (end>0) {
            int start = 0;
            while (start<end) {
                lists[start] = merge2(lists[start], lists[end]);
                start++;
                end--;
            }
        }
        return lists[0];
    }
    ListNode* merge2(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while (l1&&l2) {
            if (l1->val<l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        p->next = l1?l1:l2;
        return dummy->next;
    }
};


class Solution {
public: // priority queue with bool operator
    struct comp {
        bool operator() (ListNode* x, ListNode* y) {
            return x->val>y->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        priority_queue<ListNode*, vector<ListNode*>, comp> q;
        for (int i=0; i<lists.size(); i++) {
            if (lists[i]) q.push(lists[i]);
        }
        while (!q.empty()) {
            p->next = q.top(); // smallest nodes are at the top
            q.pop();
            p = p->next;
            if (p->next) q.push(p->next);
        }
        return dummy->next;
    }
};