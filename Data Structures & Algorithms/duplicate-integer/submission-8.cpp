auto fast_io = []() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}();
class Solution {
public:

    bool hasDuplicate(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto i1 = std::adjacent_find(nums.begin(), nums.end());
        if (i1 == nums.end()) {
            return false;
        } else {
            return true;
        }
    }
};