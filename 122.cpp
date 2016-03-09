// 122. Best Time to Buy and Sell Stock II

class Solution {
public: // greedy
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i=1; i<prices.size(); i++) {
            res += prices[i]>prices[i-1]?prices[i]-prices[i-1]:0;
        }
        return res;
    }
};