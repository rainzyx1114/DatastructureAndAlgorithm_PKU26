#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if (num != 0) {
                nums[slow] = num;
                slow += 1;
            }
        }
        while (slow < nums.size()) {
            nums[slow] = 0;
            slow += 1;
        }
    }
};