// 374. Guess Number Higher or Lower

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        if (guess(n) == 0) {
            return n;
        } 
        int left = 0;
        int right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int t = guess(mid);
            if (t == 0) {
                return mid;
            } else if (t < 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};