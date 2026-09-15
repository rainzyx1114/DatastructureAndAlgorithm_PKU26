#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    char flag = '=';
    while (flag == '=') {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            arr[i] -= tmp;
        }
        sort(arr.begin(), arr.end());
        int l = 0;
        int r = n - 1;
        long long res = 0;
        while (l < r) {
            long long sum = arr[l] + arr[r];
            if (sum > 0) {
                res += r - l;
                r--;
            } else {
                l++;
            }
        }
        cout << res << endl;
        string s;
        cin >> s;
        cout << s << endl;
        flag = s[0];
    }
}