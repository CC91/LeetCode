// 188. Best Time to Buy and Sell Stock IV

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (prices.empty()) return 0;
        if (k>=prices.size()) return quickSolve(prices);
        vector<int> g(k+1, 0);
        vector<int> l(k+1, 0);
        for (int i=0; i<prices.size()-1; i++) {
            int diff = prices[i+1]-prices[i];
            for (int j=k; j>=1; j--) {
                l[j] = max(g[j-1]+max(diff, 0), l[j]+diff);
                g[j] = max(l[j], g[j]);
            }
        }
        return g[k];
    }
    
    int quickSolve(vector<int>& prices) {
        int res = 0;
        for (int i=1; i<prices.size(); i++) {
            if (prices[i]-prices[i-1]>0) res+=prices[i]-prices[i-1];
        }
        return res;
    }
};