class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ret_arr = {0,1};
        unordered_map<int,int> dict = {{0, 0}, {1, 1}};
        if (n == 0){
            return {0};
        } else if (n == 1){
            return {0,1};
        }

        for (int i = 2; i <= n; ++i){
            int i_val;
            if (i & 1){
                i_val = 1 + dict[i/2];
                ret_arr.push_back(i_val);
            } else {
                i_val = dict[i/2];
                ret_arr.push_back(i_val);
            }
            dict[i] = i_val;
        }
        return ret_arr;
    }
};
