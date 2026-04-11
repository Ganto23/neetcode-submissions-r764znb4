class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int l = 0;
        int r = 0;
        std::vector<int> out_arr;
        out_arr.reserve(nums.size()-k+1);
        std::priority_queue<std::pair<int, int>> max_heap;

        while (r < k) {
            max_heap.push({nums[r], r});
            r++;
        }

        while (r <= nums.size()) {
            while (max_heap.top().second >= r || max_heap.top().second < l) {
                max_heap.pop();
            }
            out_arr.push_back(max_heap.top().first);

            max_heap.push({nums[r], r});
            r++;

            l++;
        }
        return out_arr;
    }
};
