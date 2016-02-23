// 215. Kth Largest Element in an Array

class Solution {
public: // priority queue, keep largest value at the top
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,  less<int>> q;
        for (int n:nums) q.push(n);
        for (int i=1; i<k; i++) q.pop();
        return q.top();
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>,  less<int>> q;
        for (int n:nums) q.push(n);
        for (int i=1; i<k; i++) q.pop();
        return q.top();
    }
};