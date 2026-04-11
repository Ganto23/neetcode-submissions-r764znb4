class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return {};
        
        std::vector<int> out_arr;
        out_arr.reserve(n - k + 1);
        
        std::deque<int> dq;

        for (int i = 0; i < n; ++i) {
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }

            dq.push_back(i);

            if (i >= k - 1) {
                out_arr.push_back(nums[dq.front()]);
            }
        }
        
        return out_arr;
    }
};