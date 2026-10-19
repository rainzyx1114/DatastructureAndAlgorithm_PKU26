#include<vector>

using namespace std;



class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int target = 0;
        for (int n : nums) {
            target += n;
        }
        target -= x;
        if (target < 0) return -1;

        int left = 0;
        int sum = 0;
        int maxLen = -1;
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];

            while (left <= right && sum > target) {                
                sum -= nums[left];
                left += 1;
            }

            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return maxLen == -1 ? -1 : nums.size() - maxLen;
    }
};