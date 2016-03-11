// 283. Move Zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0; // j indicates the position of the potential 0
        for (int i=0; i<nums.size(); i++) {
            if (nums[i]!=0) swap(nums[i], nums[j++]); // swap non-zero elements and 0's
        }
    }
};