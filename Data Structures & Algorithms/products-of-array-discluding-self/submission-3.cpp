class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        std::vector<int> left(n, 1);
        std::vector<int> right(n, 1);
        std::vector<int> output(n, 1);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                left[i] = nums[i];
            } else {
                left[i] = left[i-1] * nums[i];
            }
        }

        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                right[i] = nums[i];
            } else {
                right[i] = right[i+1] * nums[i];
            }
        }

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                output[i] = right[i+1];
            } else if (i == n-1) {
                output[i] = left[i-1];
            } else {
                output[i] = left[i-1] * right[i+1];
            }
        }
        return output;
    }
};
