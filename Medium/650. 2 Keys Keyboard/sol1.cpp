class Solution {
public:
    int minSteps(int n) {
        vector<int> v(1001, 0);
        for (int i = 2; i <= n; i++) {
            int f = largestFactor(i);
            if (f == 1)
                v[i] = i;
            else
                v[i] = v[f] + i/f;
        }
        return v[n];
    }

    int largestFactor(int n) {
        int s = sqrt(n);
        for (int i = 2; i <= s; i++) {
            if (n % i == 0)
                return max(i, n/i);
        }
        return 1;
    }
};