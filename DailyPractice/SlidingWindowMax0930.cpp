#include <vector>
#include <deque>
using namespace std;

deque<int> dq;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        for (int i = 0; i < k - 1; ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        int maxLen = nums.size() - k + 1;
        int l = 0;
        int r = k - 1;
        while(l < maxLen) {
            while (!dq.empty() && nums[r] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);
            res.push_back(nums[dq.front()]);
            if (dq.front() == l) {
                dq.pop_front();
            }
            l++;
            r++;
        }
        return res;
    }
};