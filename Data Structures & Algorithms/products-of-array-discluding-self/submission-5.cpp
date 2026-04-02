class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        std::vector<int> output(nums.size());
        std::exclusive_scan(nums.begin(), nums.end(), output.begin(), 1, std::multiplies<int>());
        int suffixProd = 1;
        std::transform(output.rbegin(), output.rend(), nums.rbegin(), output.rbegin(),
            [&suffixProd](int outVal, int numVal) {
                int res = outVal * suffixProd;
                suffixProd *= numVal;
                return res;
            });

        return output;

    }
};
