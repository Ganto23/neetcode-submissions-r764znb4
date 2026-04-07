class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        std::vector<int> left_heights(n, 0);
        left_heights.reserve(n);
        for (int i = 1; i < n; ++i) {
            left_heights[i] = std::max(left_heights[i-1], height[i-1]);
        }

        std::vector<int> right_heights(n, 0);
        right_heights.reserve(n);
        for (int i = n-2; i >= 0; --i) {
            right_heights[i] = std::max(right_heights[i+1], height[i+1]);
        }

        int total_water = 0;

        for (int i = 1; i < n-1; ++i){
            total_water += std::max(std::min(left_heights[i], right_heights[i]) - height[i], 0);
        }
        return total_water;
    }
};
