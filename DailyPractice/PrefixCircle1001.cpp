#include <iostream>

using namespace std;

void nextArray(int *next, const string& str) {
    next[0] = -1;
    next[1] = 0;
    int i = 2;
    int j = 0;
    while (i <= str.size()) {
        if (str[i - 1] == str[j]) {
            j += 1;
            next[i] = j;
            i += 1;
        } else if (j > 0) {
            j = next[j];
        } else {
            next[i] = 0;
            i += 1;
        }
    }
}

int main() {
    int len;
    int cnt = 1;
    while (cin >> len && len != 0) {
        cout << "Test case #" << cnt << endl;
        cnt += 1;
        string str;
        cin >> str;
        int next[len];
        nextArray(next, str);
        for (int i = 2; i <= len; ++i) {
            int cycleLen = i - next[i];
            if (i % cycleLen == 0 && i != cycleLen) {
                cout << i << ' ' << i / cycleLen << endl;
            }
        }
        cout << endl;
    }
}