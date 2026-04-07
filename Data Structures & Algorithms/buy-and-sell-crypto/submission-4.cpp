class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ret_val = 0;
        int lowest_price_so_far = prices[0];

        for (int i = 1; i < n; ++i) {
            ret_val = std::max(ret_val, prices[i] - lowest_price_so_far);
            lowest_price_so_far = std::min(prices[i], lowest_price_so_far);
        }
        return ret_val;
    }
};
