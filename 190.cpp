// 190. Reverse Bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            if (n & 1) {
                res = (res << 1) + 1;
            } else {
                res <<= 1;
            }
            n >>= 1;
        }
        return res;
    }
};