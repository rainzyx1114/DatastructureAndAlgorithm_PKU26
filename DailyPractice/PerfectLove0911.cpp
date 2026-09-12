#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> gifts(n);
    for (int i = 0; i < n; i++) {
        cin >> gifts[i];
    }
    int prefixSum = 0;
    unordered_map<int, int> prefixToIndex;
    prefixToIndex[0] = 0;
    int maxLen = 0;
    for (int i = 1; i <= n; i++) {
        prefixSum += gifts[i - 1] - 520;
        if (prefixToIndex.find(prefixSum) != prefixToIndex.end()) {
            maxLen = max(maxLen, i - prefixToIndex[prefixSum]);
        } else {
            prefixToIndex[prefixSum] = i;
        }
    }
    cout << 520 * maxLen;
}