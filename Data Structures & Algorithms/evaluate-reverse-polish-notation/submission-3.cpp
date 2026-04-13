class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::vector<int> my_stack;
        my_stack.reserve(3);

        for (const auto& s : tokens) {
            int num1; int num2;
            if (s == "+") {
                num1 = my_stack.back(); my_stack.pop_back();
                num2 = my_stack.back(); my_stack.pop_back();
                my_stack.push_back(num1 + num2);
            } else if (s == "-") {
                num1 = my_stack.back(); my_stack.pop_back();
                num2 = my_stack.back(); my_stack.pop_back();
                my_stack.push_back(num2 - num1);
            } else if (s == "*") {
                num1 = my_stack.back(); my_stack.pop_back();
                num2 = my_stack.back(); my_stack.pop_back();
                my_stack.push_back(num1 * num2);
            } else if (s == "/") {
                num1 = my_stack.back(); my_stack.pop_back();
                num2 = my_stack.back(); my_stack.pop_back();
                my_stack.push_back(num2 / num1);
            } else {
                my_stack.push_back(stoi(s));
            }
            std::cout << s << std::endl;
        }
        return my_stack[0];
    }
};
