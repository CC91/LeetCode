// 24. Swap Nodes in Pairs

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // Recursion
    ListNode* swapPairs(ListNode* head) {
        if (!head ||!head->next) return head;
        ListNode* nextPair = head->next->next;
        ListNode* newHead = head->next;
        head->next->next = head;
        head->next = swapPairs(nextPair);
        return newHead;
    }
};


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        ListNode *p1 = dummy, *p2 = head;
        dummy->next = head;
        while (p2&&p2->next) {
            ListNode *tmp = p2->next->next;
            p2->next->next = p2; // or = p1->next
            p1->next = p2->next;
            p2->next = tmp;
            p1 = p2;
            p2 = tmp;
        }
        return dummy->next;
    }
};