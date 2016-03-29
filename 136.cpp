// 136. Single Number

class Solution {
public: // XOR, O(n) time, O(1) space
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int n:nums) res ^= n;
        return res;
    }
};


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
    }
};