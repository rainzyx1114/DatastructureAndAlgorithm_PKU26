#include<iostream>
using namespace std;

class Solution {
public:
    int cnt[255] = {0};
    string minWindow(string s, string t) {
        int debt = 0;
        for (char c: t) {
            cnt[c]--;
            debt++;
        }
        int len = 1e6;
        int l = -1;
        int start = -1;
        for (int r = 0; r < s.size(); r++) {
            int c = s[r];
            if (cnt[c] < 0) {
                debt--;
            }
            cnt[c]++;
            if (debt == 0) {
                while(true) {
                    l++;
                    c = s[l];
                    cnt[c]--;
                    if (cnt[c] < 0) {
                        l--;
                        cnt[c]++;
                        break;
                    }
                }
                if (len > r - l) {
                    start = l + 1;
                    len = r - l;
                }
            }
        }
        return start == -1 ? "" : s.substr(start, len);
    }
};