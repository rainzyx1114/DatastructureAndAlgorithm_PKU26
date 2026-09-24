#include<iostream>
#include<deque>
#include<vector>

using namespace std;

deque<int> minNums;
deque<int> maxNums;
vector<int> nums;
vector<int> minRes;
vector<int> maxRes;

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0, num; i < n; ++i) {
        cin >> num;
        nums.push_back(num);
    }
    for (int i = 0; i < n; ++i) {
        int num = nums[i];
        while (!minNums.empty() && nums[minNums.back()] >= num) {
            minNums.pop_back();
        }
        minNums.push_back(i);
        while (!maxNums.empty() && nums[maxNums.back()] <= num) {
            maxNums.pop_back();
        }
        maxNums.push_back(i);
        if (i - k == minNums.front()) {
            minNums.pop_front();
        }
        if (i - k == maxNums.front()) {
            maxNums.pop_front();
        }
        if (i >= k - 1) {
            minRes.push_back(minNums.front());
            maxRes.push_back(maxNums.front());
        }
    }
    for (int res : minRes) {
        cout << nums[res] << ' ';
    }
    cout << endl;
    for (int res : maxRes) {
        cout << nums[res] << ' ';
    }
}