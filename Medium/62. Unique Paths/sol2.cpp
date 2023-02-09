class Solution {
public:
    int uniquePaths(int m, int n) {
        m--;
        n--;
        return nCr(m+n, n);
    }

    int nCr(int n, int r) {
        if (r == 0)
            return 1;
        if (r > n/2)
            return nCr(n, n-r);
        long res = 1;
        for (int i = 1; i <= r; i++) {
            res *= n-i+1;
            res /= i;
        }
        return res;
    }
};

// ref: https://stackoverflow.com/questions/9330915/number-of-combinations-n-choose-r-in-c