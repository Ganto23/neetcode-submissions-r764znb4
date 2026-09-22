class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2,0));

        for (int i = n-1; i >= 0; --i) {
            for (int buying = 0; buying <= 1; ++buying) {
                int cooldown = dp[i + 1][buying];

                if (buying) {
                    int buy = dp[i + 1][0] - prices[i];
                    dp[i][buying] = max(buy, cooldown);
                } else {
                    int sell = dp[i + 2][1] + prices[i];
                    dp[i][buying] = max(sell, cooldown);
                }
            }
        }
        return dp[0][1];
    }
};
