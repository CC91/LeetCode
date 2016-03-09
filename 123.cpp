// 123. Best Time to Buy and Sell Stock III

class Solution {
public: // scan from left to right to get the first transaction max then from right to left to get the second max
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        int res = 0, minPrice = prices[0], maxPrice = prices[n-1], maxRightProfit = 0;
        vector<int>  leftProfit(n, 0);
        for (int i=1; i<n; i++) {
            minPrice = min(prices[i], minPrice);
            leftProfit[i] = max(prices[i]-minPrice, 0);
        }
        for (int i=n-2; i>=0; i--) {
            maxPrice = max(prices[i], maxPrice);
            maxRightProfit = max(maxPrice-prices[i], maxRightProfit);
            res = max(res, maxRightProfit+leftProfit[i]);
        }
        return res;
    }
};