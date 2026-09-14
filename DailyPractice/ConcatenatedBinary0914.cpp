#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int concatenatedBinary(int n) {
        int i = 1;
        int bias = 1;
        long long sum = 0;
        int mod = 1000000007;
        while (i <= n) {
            if ((i >> bias) & 1 == 1) {
                bias += 1;
            }
            sum = ((sum << bias) + i) % mod;
            i += 1;
        }
        return (int)sum;
    }
};

int main() {
    Solution s = Solution();
    cout << s.concatenatedBinary(1) << endl;
    cout << s.concatenatedBinary(3) << endl;
    cout << s.concatenatedBinary(12) << endl;
}