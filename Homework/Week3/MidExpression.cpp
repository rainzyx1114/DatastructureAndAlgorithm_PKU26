#include <iostream>
#include <stack>

using namespace std;

stack<char> ops;
stack<int> nums;
bool judge(char op) {
    if (ops.empty() || op == '(') return true;
    char curOp = ops.top();
    if (op == '+' || op == '-') {
        return curOp == '(';
    } else if (op == '*' || op == '/') {
        return curOp == '+' || curOp == '-' || curOp == '(';
    }
    return false;
}
void cal(char op) {
    int r = nums.top(); nums.pop();
    int l = nums.top(); nums.pop();
    switch(op) {
        case '+': nums.push(l + r); break;
        case '-': nums.push(l - r); break;
        case '*': nums.push(l * r); break;
        case '/': nums.push(l / r); break;
    }
}
void clear() {
    while (!ops.empty()) {
        ops.pop();
    }
    while (!nums.empty()) {
        nums.pop();
    }
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        clear();
        string s;
        cin >> s;
        string num = "";
        for (char c : s) {
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(') {
                if (num != "") {
                    nums.push(stoi(num));
                    num = "";
                }
                if (judge(c)) {
                    ops.push(c);
                } else {
                    while (!judge(c)) {
                        cal(ops.top());
                        ops.pop();
                    }
                    ops.push(c);
                }
            } else if (c == ')') {
                if (num != "") {
                    nums.push(stoi(num));
                    num = "";
                }
                while (ops.top() != '(') {
                    cal(ops.top());
                    ops.pop();
                }
                ops.pop();
            } else {
                num = num + c;
            }
        }
        if (num != "") {
            nums.push(stoi(num));
        }
        while (!ops.empty()) {
            cal(ops.top());
            ops.pop();
        }
        cout << nums.top() << endl;
    }
}