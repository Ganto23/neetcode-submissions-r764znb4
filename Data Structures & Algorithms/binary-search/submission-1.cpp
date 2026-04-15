class Solution {
public:
    int search(vector<int>& nums, int target) {
        int base = 0;
        int len = nums.size();

        while (len > 0) {
            int half = len / 2;
            int mid = base + half;
            
            bool is_less = nums[mid] < target;
            
            base = is_less ? mid + 1 : base;
            len = is_less ? len - half - 1 : half;
        }
        if (base < nums.size() && nums[base] == target) {
            return base;
        }
        
        return -1;
    }
};