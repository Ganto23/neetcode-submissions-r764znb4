class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1 && nums[0] == target){
            return 0;
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;

            if (nums[m] == target){
                return m;
            } else if (nums[l] == target){
                return l;
            } else if (nums[r] == target) {
                return r;
            }

            if (nums[m] > target && nums[l] < target) {
                r = m;
            } else if (nums[m] < nums[l]){
                r = m;
            } else {
                l = m + 1;
            }
        }
        return -1;
    }
};
