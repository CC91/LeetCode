// 202. Happy Number

class Solution {
public:
    bool isHappy(int n) {
        set<int> m;
        while (n!=1) {
            int sum = 0;
            while (n>0) {
                sum += (n%10)*(n%10);
                n /= 10;
            }
            n = sum;
            if (m.count(n)) break;
            else m.insert(n);
        }
        return n==1;
    }
};


class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while (n!=1) {
            int sum = 0;
            while (n>0) {
                sum += (n%10)*(n%10);
                n /= 10;
            }
            n = sum;
            if (m.count(n)) break;
            else m[n] = 0;
        }
        return n==1;
    }
};