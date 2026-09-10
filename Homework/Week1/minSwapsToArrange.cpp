#include <vector>
using namespace std;

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> rightZeros(n);
        for (int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                if (grid[i][j] == 0) {
                    rightZeros[i] += 1;
                } else {
                    break;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            bool canFind = false;
            for (int j = i; j < n; j++) {
                if (rightZeros[j] >= n - 1 - i) {
                    canFind = true;
                    res += j - i;
                    while (j != i) {
                        swap(rightZeros[j], rightZeros[j - 1]);
                        j -= 1;
                    }
                    break;
                }
            }
            if (!canFind) {
                return -1;
            }
        }
        return res; 
    }
};