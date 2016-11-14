// 442. Find All Duplicates in an Array

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        int idx = 0;
        for (int i = 0; i < nums.size(); i++) {
            idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) {
                res.push_back(idx + 1);
            }
            nums[idx] *= -1;
        }
        return res;
    }
};