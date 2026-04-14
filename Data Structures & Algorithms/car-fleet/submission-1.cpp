class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        std::vector<double> time_stack;

        std::vector<int> indices(position.size());
        std::iota(indices.begin(), indices.end(), 0);
        std::sort(indices.begin(), indices.end(), [&](int i, int j) {
            return position[i] > position[j]; 
        });

        for (auto idx : indices) {
            double cur_time = static_cast<double>(target - position[idx]) / speed[idx];
            if (time_stack.empty()) {
                time_stack.push_back(cur_time);
            } else {
                double prev_time = time_stack.back();
                if (cur_time > prev_time) {
                    time_stack.push_back(cur_time);
                }
            }
        }
        return time_stack.size();
    }
};
