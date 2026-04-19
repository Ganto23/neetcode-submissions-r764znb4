class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const vector<int>& smaller = (nums1.size() < nums2.size()) ? nums1 : nums2;
        const vector<int>& larger = (nums1.size() < nums2.size()) ? nums2 : nums1;
        
        int n = smaller.size();
        int m = larger.size();
        
        int l = 0;
        int r = n;
        int half = (n + m + 1) / 2;
        
        while (l <= r) {
            int mid1 = l + (r - l) / 2;
            int mid2 = half - mid1;
            
            int maxLeftSmaller = (mid1 == 0) ? std::numeric_limits<int>::min() : smaller[mid1 - 1];
            int minRightSmaller = (mid1 == n) ? std::numeric_limits<int>::max() : smaller[mid1];
            
            int maxLeftLarger = (mid2 == 0) ? std::numeric_limits<int>::min() : larger[mid2 - 1];
            int minRightLarger = (mid2 == m) ? std::numeric_limits<int>::max() : larger[mid2];
            
            if (maxLeftSmaller <= minRightLarger && maxLeftLarger <= minRightSmaller) {
                if ((n + m) % 2 == 0) {
                    return (std::max(maxLeftSmaller, maxLeftLarger) + std::min(minRightSmaller, minRightLarger)) / 2.0;
                } else {
                    return std::max(maxLeftSmaller, maxLeftLarger);
                }
            } else if (maxLeftSmaller > minRightLarger) {
                r = mid1 - 1;
            } else {
                l = mid1 + 1;
            }
        }
        
        return 0.0;
    }
};