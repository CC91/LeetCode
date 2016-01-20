// 123. Best Time to Buy and Sell Stock III

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> leftProfit(n, 0);
        int minPrice = prices[0], maxLeftProfit = 0;
        for (int i=1; i<n; i++) {
            if (prices[i]<minPrice) {
                minPrice = prices[i];
            }
            else maxLeftProfit = max(maxLeftProfit, prices[i]-minPrice);
            leftProfit[i] = maxLeftProfit;
        }
        int res = leftProfit[n-1], maxPrice = prices[n-1], maxRightProfit = 0;
        for (int i=n-2; i>=0; i--) {
            if (prices[i]>maxPrice) maxPrice = prices[i];
            else maxRightProfit = max(maxRightProfit, maxPrice-prices[i]);
            res = max(res, maxRightProfit+leftProfit[i]);
        }
        return res;
    }
};