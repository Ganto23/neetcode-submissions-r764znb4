class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int cur_cost = 0;
        int n = cost.size();
        int cur_minus_2 = 0, cur_minus_1 = 0; 

        for (int i = 2; i <= n; ++i) {
            cur_cost = min(cost[i-1] + cur_minus_1, cost[i-2] + cur_minus_2);
            cur_minus_2 = cur_minus_1;
            cur_minus_1 = cur_cost;
        }
        return cur_cost;
    }
};
