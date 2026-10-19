#include<stack>
using namespace std;

class MinStack {
public:
    stack<int> s;
    MinStack() {}
    
    void push(int value) {
        if (s.empty()) {
            s.push(value);
            s.push(value);
        } else {
            int m = value < s.top()? value : s.top();
            s.push(value);
            s.push(m);
        }
    }
    
    void pop() {
        s.pop();
        s.pop();
    }
    
    int top() {
        int tmp = s.top();
        s.pop();
        int res = s.top();
        s.push(tmp);
        return res;
    }
    
    int getMin() {
        return s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */