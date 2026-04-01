class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        //std::unordered_map<int, int> count;
        //count.reserve(nums.size());
        std::vector<int> count(2001, 0);
        std::vector<int> output;

        for (const auto& n : nums){
            count[n + 1000]++;
        }

        //for (auto& [idx, group] : count) {
        //    buckets[group].push_back(idx);
        //}

        for (int i = 0; i < count.size(); i++){
            buckets[count[i]].push_back(i - 1000);
        }

        for (auto it = buckets.rbegin(); it != buckets.rend(); it++){
            for (const auto& n : *it) {
                output.push_back(n);
                if (output.size() == k){
                    return output;
                }
            }
        }
        return output;
    }
};
