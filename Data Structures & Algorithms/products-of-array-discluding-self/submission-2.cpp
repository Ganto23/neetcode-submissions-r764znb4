class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        const int n = nums.size();
        vector<int> ret_arr(n, 1);

        int left_product = 1;
        for(int i = 0; i < n; ++i){
            ret_arr[i] = left_product;
            left_product *= nums[i];
        }

        int right_product = 1;
        for (int i = n-1; i >= 0; --i){
            ret_arr[i] *= right_product;
            right_product *= nums[i];
        }

        return ret_arr;
    }
};
