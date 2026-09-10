#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), 
        [](int a, int b){
            int aStore = a;
            int bStore = b;
            int aSum = 0;
            for (int i = 0; i < 32; i++) {
                aSum += (a & 1);
                a = a >> 1;
            }
            int bSum = 0;
            for (int i = 0; i < 32; i++) {
                bSum += (b & 1);
                b = b >> 1;
            }
            if (aSum != bSum) {
                return aSum < bSum;
            } else {
                return aStore < bStore;
            }
        });
        return arr;
    }
};