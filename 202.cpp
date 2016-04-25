// 202. Happy Number 

class Solution {
public: // set
    bool isHappy(int n) {
        set<int> s;
        while (n!=1 && !s.count(n)) {
            s.insert(n);
            int sum = 0;
            while (n) {
                sum += (n%10)*(n%10);
                n /= 10;
            }
            n = sum;
        }
        return n==1;
    }
};


class Solution {
public: // hashmap
    bool isHappy(int n) {
        unordered_map<int, int> m;
        while (n!=1) {
            int sum = 0;
            while (n) {
                sum += (n%10)*(n%10);
                n /= 10;
            }
            n = sum;
            if (m.count(n)) break;
            else m[n] = 1;
        }
        return n==1;
    }
};