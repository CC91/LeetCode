// 393. UTF-8 Validation

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int cnt = 0;
        for (auto a : data) {
            if (0 == cnt) {
                if ((a >> 5) == 0b110) {
                    cnt = 1;
                } else if ((a >> 4) == 0b1110) {
                    cnt = 2;
                } else if ((a >> 3) == 0b11110) {
                    cnt = 3;
                } else if (a >> 7) {
                    return false;
                }
            } else {
                if ((a >> 6 != 0b10)) {
                    return false;
                }
                cnt--;
            }
        }
        return cnt == 0;
    }
};