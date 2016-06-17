// 260. Single Number III

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int n : nums) {
            if (s.count(n)) {
                s.erase(n);
            } else {
                s.insert(n);
            }
        }
        return vector<int> (s.begin(), s.end());
    }
};


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int two = accumulate(nums.begin(), nums.end(), 0, bit_xor<int> ());
        two &= -two;
        vector<int> res(2, 0);
        for (auto a : nums) {
            if (a & two) {
                res[0] ^= a;
            } else {
                res[1] ^= a;
            }
        }
        return res;
    }
};