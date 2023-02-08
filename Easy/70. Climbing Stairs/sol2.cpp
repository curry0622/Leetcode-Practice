class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 || n == 2)
            return n;
        int a = 1, b = 2, c;
        for (int i = 3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

// n=1: [1]
// n=2: [1, 1], [2]
// n=3: [1, 2], [2, 1]
// n=4: [1, 3], [2, 2]
// n=n: [1, n-1], [2, n-2]