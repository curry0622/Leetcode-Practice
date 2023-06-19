class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        long i;
        for (i = 0; i < x; i++) {
            if (i * i > x)
                break;
        }
        return i - 1;
    }
};