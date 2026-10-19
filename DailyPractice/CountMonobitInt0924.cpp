class Solution {
public:
    int countMonobit(int n) {
        int cnt = 0;
        n += 1;
        while (n != 0) {
            n = n >> 1;
            cnt += 1;
        }
        return cnt;
    }
};