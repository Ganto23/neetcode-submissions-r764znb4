class MinStack {
    std::vector<int> my_stack;
    std::vector<int> min_element;
public:
    MinStack() {
        min_element.reserve(2000);
    }
    
    void push(int val) {
        if (min_element.empty() || val <= min_element.back()) min_element.push_back(val);
        my_stack.push_back(val);
    }
    
    void pop() {
        if (my_stack.back() == min_element.back()) min_element.pop_back();
        my_stack.pop_back();
    }
    
    int top() {
        return my_stack.back();
    }
    
    int getMin() {
        return min_element.back();
    }
};
