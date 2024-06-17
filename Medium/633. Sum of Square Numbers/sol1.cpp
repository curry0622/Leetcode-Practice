class Solution {
public:
    bool judgeSquareSum(int c) {
        long l = 0, r = sqrt(c);
        while (l <= r) {
            long tmp = l*l + r*r;
            if (tmp == c)
                return true;
            if (tmp > c) {
                r--;
            } else {
                l++;
            }
        }
        return false;
    }
};