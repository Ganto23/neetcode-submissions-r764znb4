class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water{};

        int l = 0; int r = heights.size() - 1;

        while (l < r) {
            max_water = std::max((r - l) * std::min(heights[l], heights[r]), max_water);
            if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
            }
        }
        return max_water;
    }
};
