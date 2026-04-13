class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> result(temperatures.size(), 0);
        std::vector<std::pair<int,int>> my_stack;

        for (int i = 0; i < temperatures.size(); ++i) {
            while (!my_stack.empty() && temperatures[i] > my_stack.back().first) {
                result[my_stack.back().second] = i - my_stack.back().second;
                my_stack.pop_back();
            }
            my_stack.push_back({temperatures[i], i});
        }
        return result;
    }
};
