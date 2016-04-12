// 147. Insertion Sort List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public: // need a dummy node
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        while (head) {
            ListNode *node = dummy;
            while (node->next && node->next->val<head->val) node = node->next;
            ListNode *tmp = head->next;
            head->next = node->next;
            node->next = head;
            head = tmp;
        }
        return dummy->next;
    }
};