class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> v(n, 1);
        int t2 = 0, t3 = 0, t5 = 0;
        for (int i = 1; i < n; i++) {
            v[i] = min(2 * v[t2], min(3 * v[t3], 5*v[t5]));
            if (v[i] == 2 * v[t2]) t2++;
            if (v[i] == 3 * v[t3]) t3++;
            if (v[i] == 5 * v[t5]) t5++;
        }
        return v.back();
    }
};