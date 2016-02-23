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
public: // Divide and Conquer, merge every head and tail lists
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
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* tmp = dummy;
        while (l1 && l2) {
            if (l1->val<l2->val) {
                tmp->next = l1;
                l1 = l1->next;
            } else {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        tmp->next = l1?l1:l2;
        return dummy->next;
    }
};


class Solution {
public: // priority queue, since it is linked list, we can't use default greater/less operator in PQ. Define a new struct with bool operator
    struct comp{
        bool operator() (ListNode* x, ListNode* y) {
            return x->val>y->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(INT_MIN);
        ListNode* tmp = dummy;
        priority_queue<ListNode*, vector<ListNode*>, comp> q;
        for (int i=0; i<lists.size(); i++) {
            if (lists[i]) q.push(lists[i]);
        }
        while (!q.empty()) {
            tmp->next = q.top();
            q.pop();
            tmp = tmp->next;
            if (tmp->next) q.push(tmp->next);
        }
        return dummy->next;
    }
};