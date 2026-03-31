class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0){
            return 0;
        }
        int max_profit = 0;
        int p = 1;
        int smallest_so_far = prices[0];
        int curr;

        while (p < prices.size()){
            smallest_so_far = min(prices[p-1],smallest_so_far);
            int profit = prices[p] - smallest_so_far;
            max_profit = max(max_profit,profit);
            p++;
        }
        return max_profit;
        
    }
};
