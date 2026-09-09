class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    MinStack() {
    }

    void push(int val) {
        mainStack.push(val);

        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    int top() {
        return mainStack.top();
    }

    void pop() {
        int topVal = mainStack.top();
        mainStack.pop();

        if (topVal == minStack.top()) {
            minStack.pop();
        }
    }

    int getMin() {
        return minStack.top();
    }
};
