class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if (accumulate(gas.begin(), gas.end(), 0) < accumulate(cost.begin(), cost.end(), 0)) return -1;

        for (int i = 0; i < gas.size(); ++i) {
            gas[i] -= cost[i];
        }

        int start = 0; int cur_sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            cur_sum += gas[i];
            if (cur_sum < 0) {
                start = i+1;
                cur_sum = 0;
            }
        }
        return start;
    }
};
