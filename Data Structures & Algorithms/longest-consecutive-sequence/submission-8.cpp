class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> my_set(nums.begin(), nums.end());

        int total_count{};

        while (!my_set.empty()) {
            int num = *my_set.begin();
            my_set.erase(my_set.begin());
            
            int cur_count = 1;
            
            int upper = num + 1;
            while (my_set.erase(upper)) {
                cur_count++;
                upper++;
            }
            
            int lower = num - 1;
            while (my_set.erase(lower)) {
                cur_count++;
                lower--;
            }
            
            total_count = std::max(total_count, cur_count);
        }
        return total_count;
    }
};
