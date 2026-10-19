#include <iostream>
using namespace std;

int main() {
    string s;
    string t;
    while(cin >> s >> t) {
        int index = 0;
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] == s[index]) {
                index++;
            }
            if (index == s.size()) {
                break;
            }
        }
        cout << (index == s.size() ? "Yes" : "No")<< endl;
    }
}