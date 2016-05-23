// 309. Best Time to Buy and Sell Stock with Cooldown

class Solution {
public: // DP: buy[i] = max(buy[i - 1], sell[i - 2] - prices[i]), sell[i] = max(sell[i - 1], buy[i - 1] + prices[i])
    int maxProfit(vector<int>& prices) {
        int buy = INT_MIN;
        int sell = 0;
        int prev_sell = 0;
        int prev_buy = 0;
        for (int p : prices) {
            prev_buy = buy;
            buy = max(prev_buy, prev_sell - p);
            prev_sell = sell;
            sell = max(sell, prev_buy + p);
        }
        return sell;
    }
};