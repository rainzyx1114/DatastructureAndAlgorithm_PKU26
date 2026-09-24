using namespace std;
class Solution {
public:
    int numSteps1(string s) {
        int steps = 0;
        while (s != "1") {
            if (s[s.size() - 1] == '0') {
                div2(s);
            } else {
                inc(s);
            }
            steps += 1;
        }
        return steps;
    }
    void inc(string& s) {
        int carry = 1;
        for (int i = s.size() - 1; i >= 0; i--) {
            int sum = (s[i] - '0') + carry;
            carry = sum / 2;
            sum %= 2;
            s[i] = (char)('0' + sum);
        }
        if (carry == 1) {
            s = "1" + s;
        }
    }
    void div2(string& s) {
        s = s.substr(0, s.size() - 1);
    }
    int numSteps(string s) {
        int ans = 0;
        int carry = 0;
        for (int i = s.size() - 1; i > 0; i--) {
            if ((s[i] - '0') ^ carry) {
                ans += 2;
                carry = 1;
            } else {
                ans += 1;
            }
        }
        return ans + carry;
    }
};