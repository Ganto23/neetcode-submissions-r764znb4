class Solution {
public:
    int findMin(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        if (nums[0] < nums.back()) return nums[0];
        if (nums.size() == 1) return nums[0];
        if (nums.back() < nums[nums.size()-2]) return nums.back();

        int l = 0;
        int r = nums.size()-1;

        while (l < r) {
            int mid = l + (r-l)/2;

            if (nums[mid] < nums[mid-1]) {
                return nums[mid];
            } else if (nums[mid] >= nums[0]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }

        }
    }
};
