#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int len = 2 * n - 1;
    int arr[len][len];
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            arr[i][j] = 0;
        }
    }
    int i = 0;
    int j = n - 1;
    int cnt = 0;
    while (cnt < (len * len)) {
        arr[i][j] = cnt + 1;
        cnt++;
        if (i == 0) {
            if (j == len - 1) {
                i = i + 1;
            } else {
                i = len - 1;
                j = j + 1;
            }
        } else if (j == len - 1) {
            i = i - 1;
            j = 0;
        } else {
            i = i - 1;
            j = j + 1;
            if (arr[i][j] != 0) {
                i = i + 2;
                j = j - 1;
            }
        }
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}