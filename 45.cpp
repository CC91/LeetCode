// 45. Jump Game II

class Solution {
public:
    int jump(vector<int>& nums) {
        int i = 0, curMax = 0, lastMax = 0, res = 0;
        while (curMax<nums.size()-1) {
            lastMax = curMax;
            for (; i<=lastMax; i++) curMax = max(curMax, nums[i]+i);
            res++;
        }
        return res;
    }
};