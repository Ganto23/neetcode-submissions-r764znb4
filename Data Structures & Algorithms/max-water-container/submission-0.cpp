class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int max = 0;

        while (l < r){
            int lower_height = min(heights[l],heights[r]);
            int area = lower_height * (r-l);
            if (area > max){
                max = area;
            }
            if (heights[l] < heights[r]){
                l++;
            } else {
                r--;
            }
        }
        return max;
    }
};
