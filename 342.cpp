// 342. Power of Four

class Solution {
public: // math
    bool isPowerOfFour(int num) {
        while (num && num % 4 == 0) {
            num /= 4;
        }
        return num == 1;
    }
};


class Solution {
public:
    bool isPowerOfFour(int num) {
        return fmod(log10(num) / log10(4), 1) == 0;
    }
};


class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555) > 0; // or (num & 0x55555555) == num 
    }
};


class Solution {
public:
    bool isPowerOfFour(int num) {
        return num > 0 && !(num & (num - 1)) && (num - 1) % 3 == 0;
    }
};