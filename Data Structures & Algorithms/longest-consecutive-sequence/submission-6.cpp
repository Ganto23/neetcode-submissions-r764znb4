class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> my_set(nums.begin(), nums.end(), nums.size());

        int total_count{};

        for (auto num : my_set) {
            if (my_set.contains(num-1)) continue;
            int cur_count{};
            
            while (my_set.contains(num)) {
                cur_count++;
                num++;
            }
            total_count = std::max(total_count, cur_count);
        }
        return total_count;
    }
};
