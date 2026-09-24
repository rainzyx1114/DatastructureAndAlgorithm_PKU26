#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> seq;
stack<int> s;
vector<pair<string, int>> process;

int main() {
    int n;
    cin >> n;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        seq.push_back(num);
    }
    int cur = 0;
    for (int i = 1; i <= n; ++i) {
        s.push(i);
        process.push_back(make_pair("PUSH", i));
        while (!s.empty() && s.top() == seq[cur]) {
            int tmp = s.top();
            s.pop();
            process.push_back(make_pair("POP", tmp));
            cur += 1;
        }
    }
    if (!s.empty() || n <= 0) {
        cout << "NO" << endl;
    } else {
        for (auto p : process) {
            cout << p.first << ' ' << p.second << endl;
        }
    }
}