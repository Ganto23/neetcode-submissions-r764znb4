class Solution {
public:
    int findMin(vector<int> &nums) {

        int low = 0;
        int high = nums.size()-1;
        int prev_index;
        int index = (int)(low+high)/2;
        int mid;

        if (high < 10){
            std::sort(nums.begin(),nums.end());
            return nums[0];
        }

        while (low < high){

            if (low == high-1){
                return min(nums[low],nums[high]);
            }

            mid = (int)(low+high)/2;
            cout << mid << endl;
            if (nums[mid] < nums[0]){
                high = mid;
            } else if (nums[mid] > nums[0]){
                low = mid;
            } else {
                return nums[0];
            }
        }
        return nums[mid];

    }
};
