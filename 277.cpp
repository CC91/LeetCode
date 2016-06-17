// 277. Find the Celebrity

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        vector<bool> celebrity(n, false);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if (!knows(i, j) && knows(j, i)) {
                        celebrity[i] = true;
                    } else {
                        celebrity[i] = false;
                        break;
                    }
                }
            }
            if (celebrity[i]) {
                return i;
            }
        }
        return -1;
    }
};



// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int j = 0;
        for (int i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (i != j && (knows(i, j) || !knows(j, i))) {
                    break;
                } 
            }
            if (j == n) {
                return i;
            }
        }
        return -1;
    }
};



// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (knows(res, i)) {
                res = i;
            }
        }
        for (int i = 0; i < n; i++) {
            if (res != i && (knows(res, i) || !knows(i, res))) {
                return -1;
            }
        }
        return res;
    }
};