class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int temp_furthest = 0;
        int furthest = 0;

        for (int i = 0; i < nums.size()-1; ++i) {
            if (i + nums[i] > temp_furthest) {
                temp_furthest = i + nums[i];
            }
            if (i >= furthest) {
                jumps++;
                furthest = temp_furthest;
            }
        }
        return jumps;
    }
};
