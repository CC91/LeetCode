// 9. Palindrome Number

class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false; // negative integers can't be palindromes
        int factor = 1;
        while (x/factor >= 10) factor *= 10;
        while (x) {
            int head = x/factor, tail = x%10;
            if (head!=tail) return false;
            x = (x%factor)/10;
            factor /= 100;
        }
        return true;
    }
};