/*
 * 题目：剑指 Offer 30. 包含min函数的栈
 * 链接：https://leetcode-cn.com/problems/bao-han-minhan-shu-de-zhan-lcof/
 * 知识点：单调栈
 */
class MinStack {
private:
    stack<int> s;
    stack<int> minStack; // 单调栈
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if (minStack.empty() || minStack.top() >= x) {
            minStack.push(x);
        }
    }

    void pop() {
        int temp = s.top();
        s.pop();
        if (temp == minStack.top()) {
            minStack.pop();
        }
    }

    int top() {
        return s.top();
    }

    int min() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
