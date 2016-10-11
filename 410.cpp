// 410. Split Array Largest Sum

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (helper(nums, m, mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
     
    bool helper(vector<int>& nums, int m, int mid) {
        int cur = 0;
        int cnt = 1;
        for (auto a : nums) {
            cur += a;
            if (cur > mid) {
                cur = a;
                cnt++;
                if (cnt > m) {
                    return false;
                }
            }
        }
        return true;
    }
};