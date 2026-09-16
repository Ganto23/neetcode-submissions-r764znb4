class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        int prev_2 = 1, prev_1 = 2;
        for (int i = 3; i <= n; ++i) {
            int cur = prev_2 + prev_1;
            prev_2 = prev_1;
            prev_1 = cur;
        }
        return prev_1;
    }
};
