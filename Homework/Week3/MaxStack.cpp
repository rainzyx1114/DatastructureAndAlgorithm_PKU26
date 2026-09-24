#include<stack>
using namespace std;

class MaxStack {
public:
    stack<int> storeStack;
    stack<int> maxStack;
    MaxStack() {}
    
    void push(int x) {
        storeStack.push(x);
        if (maxStack.empty() || x > maxStack.top()) {
            maxStack.push(x);
        } else {
            maxStack.push(maxStack.top());
        }
    }
    
    void pop() {
        storeStack.pop();
        maxStack.pop();
    }
    
    int top() {
        return storeStack.top();
    }
    
    int getMax() {
        return maxStack.top();
    }
};