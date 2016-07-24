// 376. Wiggle Subsequence

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        vector<int> dp1(nums.size(), 1);
        vector<int> dp2(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp1[i] = max(dp1[i], dp2[j] + 1);
                } else if (nums[j] > nums[i]) {
                    dp2[i] = max(dp2[i], dp1[j] + 1);
                }
            }
        }
        return max(dp1.back(), dp2.back());
    }
};


class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2) {
            return nums.size();
        }
        int a = 1;
        int b = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                a = b + 1;
            } else if (nums[i] > nums[i - 1]) {
                b = a + 1;
            }
        }
        return max(a, b);
    }
};