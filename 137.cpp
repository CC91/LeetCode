// 137. Single Number II

class Solution {
public: // //http://www.geeksforgeeks.org/find-the-element-that-appears-once/
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0, commonBitMask; // ones record 1st, 4th, 7th numbers, twos record 2nd, 5th, 8th numbers
        for (int n:nums) {
            twos |= (ones&n);
            ones ^= n;
            commonBitMask = ~(ones&twos); // common bits in ones and twos
            ones &= commonBitMask; // remove common bits from ones and twos
            twos &= commonBitMask;
        }
        return ones;
    }
};


class Solution {
public: // use a counter to record the appeared times of a number
    int singleNumber(vector<int>& nums) {
        int w = sizeof(int)*8, res = 0; // integer bit length
        vector<int> cnt(w);
        for (int i=0; i<nums.size(); i++) {
            for (int j=0; j<w; j++) {
                cnt[j] += (nums[i]>>j) & 1;
                cnt[j] %= 3;
            }
        }
        for (int i=0; i<w; i++) res += (cnt[i]<<i);
        return res;
    }
};