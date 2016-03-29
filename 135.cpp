// 135. Candy 

class Solution {
public: // greedy, scan from left, then right
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> increment(n, 1);
        for (int i=1; i<n; i++) {
            if (ratings[i]>ratings[i-1]) increment[i] = increment[i-1]+1;
        }
        for (int i=n-2; i>=0; i--) {
            if (ratings[i]>ratings[i+1]) increment[i] = max(increment[i], increment[i+1]+1);
        }
        return accumulate(increment.begin(), increment.end(), 0);
    }
};

