class Solution {
public:
    long long minimumSteps(string s) {
        long long res = 0;
        long long blkCnt = 0;
        for (char c : s) {
            if (c == '0') {
                res += blkCnt;
            } else {
                blkCnt++;
            }
        }
        return res;
    }
};