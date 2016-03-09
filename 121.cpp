// 121. Best Time to Buy and Sell Stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, minPrice = INT_MAX;
        for (int i=0; i<prices.size(); i++) {
            minPrice = min(prices[i], minPrice);
            res = max(res, prices[i]-minPrice);
        }
        return res;
    }
};
