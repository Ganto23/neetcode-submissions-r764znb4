class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_water{};

        int l = 0; int r = heights.size() - 1;

        while (l < r) {
            int hL = heights[l];
            int hR = heights[r];
            int current_h = std::min(hL, hR);
            max_water = std::max((r - l) * current_h, max_water);
            if (hL < hR) {
                while (l < r && heights[l] <= hL) l++;
            } else {
                while (l < r && heights[r] <= hR) r--;
            }
        }
        return max_water;
    }
};
