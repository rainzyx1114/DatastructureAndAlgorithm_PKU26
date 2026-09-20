#include <iostream>

using namespace std;

int main() {
    string s;
    while (cin >> s) {
        string substr;
        cin >> substr;
        int index = 0;
        int maxnum = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] > maxnum) {
                maxnum = s[i];
                index = i;
            }
        }
        string res = s.substr(0, index + 1) + substr + s.substr(index + 1);
        cout << res << endl;
    }
}