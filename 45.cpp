// 45. Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
        int last = 0, cur = 0, res = 0, n = nums.size(); // cur is the furthest position can reach
        for (int i=0; i<n; i++) {
            if (i>last) { // last is the max distance that has been reached
                last = cur;
                res++;
            }
            cur = max(cur, nums[i]+i);
        }
        return res;
    }
};