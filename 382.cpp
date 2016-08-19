// 382. Linked List Random Node

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
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        p = head;
        len = 0;
        ListNode *t = head;
        while (t) {
            len++;
            t = t -> next;
        }
    }
     
    /** Returns a random node's value. */
    int getRandom() {
        ListNode *t = p;
        int n = rand() % len;
        while (n) {
            t = t -> next;
            n--;
        }
        return t -> val;
    }
 
private:
    int len;
    ListNode *p;
};
 
 
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        p = head;
    }
     
    /** Returns a random node's value. */
    int getRandom() {
        int res = p -> val;
        int i = 2;
        ListNode *cur = p -> next;
        while (cur) {
            int j = rand() % i;
            if (j == 0) {
                res = cur -> val;
            }
            i++;
            cur = cur -> next;
        }
        return res;
    }
 
private:
    ListNode *p;
};
 
/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */