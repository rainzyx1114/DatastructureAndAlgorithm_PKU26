class Solution {
public:
    int binaryGap(int n) {
        int slow = 0;
        int maxLen = 0;
        int len = 0;
        for (int fast = 0; fast < 32; fast++) {
            int slowNumber = (n >> slow) & 1;
            int fastNumber = (n >> fast) & 1;
            if (slowNumber == 0) {
                slow++;
            } else {
                if (fastNumber == 1) {
                    len = fast - slow;
                    maxLen = maxLen >= len? maxLen : len;
                    slow = fast;
                }
            }
        }
        return maxLen;
    }
};