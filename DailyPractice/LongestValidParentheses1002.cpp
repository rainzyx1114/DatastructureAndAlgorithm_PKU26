#include<iostream>
#include<stack>
using namespace std;

stack<char> st;


class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        int len = 0;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                    len += 2;
                } else {
                    maxLen = max(maxLen, len);
                    len = 0;
                }
            }
        }
        maxLen = max(maxLen, len);
        return maxLen;
    }
};