class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_set<int> setty;
        for (int num: nums)
            setty.insert(num);

        vector<int> starters;
        for (int num: nums){
            if (setty.find(num-1) == setty.end()){
                starters.push_back(num);
            }
        }

        int max_count = 0;
        for (int start: starters){
            int count = 1;
            int copy = start;
            while (setty.find(copy+1) != setty.end()){
                count += 1;
                copy += 1;
            }
            if (count > max_count){
                max_count = count;
            }
        }
        return max_count;

    }
};
