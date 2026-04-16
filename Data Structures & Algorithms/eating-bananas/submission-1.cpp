class Solution {
public:
    bool verify(const auto& piles, int er, int h) {
        long long cur_time = 0;
        for (const auto& bananas : piles) {
            cur_time += (bananas + er - 1) / er;
        }
        return (cur_time > h) ? false : true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = std::numeric_limits<int>::max();
        r = *std::max_element(piles.begin(), piles.end());
        int best_er = 0;

        while (l <= r) {
            int mid = l + (r-l)/2;
            if (verify(piles, mid, h)) {
                r = mid - 1;
                best_er = mid;
            } else {
                l = mid + 1;
            }
        }
        return best_er;
    }
};
