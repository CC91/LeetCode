// 55. Jump Game

class Solution {
public: // greedy, use a maxIdx to track the max idx it can reach
    bool canJump(vector<int>& nums) {
        int maxIdx = 0, n = nums.size();
        for (int i=0; i<n; i++) {
            if (i>maxIdx ||maxIdx>=(n-1)) break; // maxIdx is not big enought to reach the tail or already hit the tail
            maxIdx = max(maxIdx, nums[i]+i);
        }
        return maxIdx>=(n-1)?true:false;
    }
};