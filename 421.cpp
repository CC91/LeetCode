// 421. Maximum XOR of Two Numbers in an Array

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask |= (1 << i);
            set<int> s;
            for (auto &a : nums) {
                s.insert(a & mask);
            }
            int t = res | (1 << i);
            for (auto &prefix : s) {
                if (s.count(t ^ prefix)) {
                    res = t;
                    break;
                }
            }
        }
        return res;
    }
};