class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if (nums.size() == 0) return {};

        std::unordered_map<int,int> mymap;
        std::vector<std::vector<int>> freq(nums.size()+1);

        for (auto num : nums) {
            mymap[num]++;
        }

        for (auto& [key, value] : mymap) {
            freq[value].push_back(key);
        }

        std::vector<int> res; int added = 0;
        for (int i = freq.size()-1; i >= 0; --i) {
            for (auto num : freq[i]) {
                res.push_back(num);
                added++;
                if (added == k) return res;
            }
        }
        return res;
    }
};
