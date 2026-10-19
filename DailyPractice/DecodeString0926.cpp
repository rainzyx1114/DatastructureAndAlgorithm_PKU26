#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    stack<string> strs;
    stack<int> nums;
    string decodeString(string s) {
        string str = "";
        string num = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <='9') {
                num += s[i];
                if (str != "") {
                    strs.push(str);
                    str = "";
                }
                continue;
            }
            if (num != "") {
                nums.push(stoi(num));
                num = "";
            }
            if (s[i] == '[') {
                strs.push("[");
                if (str != "") {
                    strs.push(str);
                    str = "";
                }
                continue;
            }
            if (s[i] == ']') {
                if (str != "") {
                    strs.push(str);
                    str = "";
                }
                string s = "";
                while (strs.top() != "[") {
                    s = strs.top() + s;
                    strs.pop();
                }
                strs.pop();
                int cnt = nums.top();
                nums.pop();
                while (cnt--) {
                    strs.push(s);
                }
                continue;
            }
            str += s[i];
        }
        if (str != "") {
            strs.push(str);
        }
        string res = "";
        while(!strs.empty()) {
            res = strs.top() + res;
            strs.pop();
        }
        return res;
    }
};

class Solution2 {
    public:
    int idx;
    string str;
    // expr = string(expr) | num[expr](expr)
    string parseExpr() {
        if (idx == str.size() || str[idx] == ']') {
            return "";
        }
        string res = "";
        if (isalpha(str[idx])) {
            while (isalpha(str[idx])) {
                res += str[idx];
                idx++;
            }
        } else if (isdigit(str[idx])) {
            while (isdigit(str[idx])) {
                res += str[idx];
                idx++;
            }
            int cnt = stoi(res);
            res = "";
            idx++;
            string tmp = parseExpr();
            idx++;
            while(cnt--) {
                res += tmp;
            }
        }
        return res + parseExpr();
    }

    string decodeString(string s) {
        idx = 0;
        str = s;
        return parseExpr();
    }
};