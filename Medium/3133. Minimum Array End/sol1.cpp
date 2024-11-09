class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> vec(64, 0);
        int i = 0;
        while (x > 0) {
            vec[i++] = x % 2;
            x /= 2;
        }
        --n;
        for (int i = 0; n > 0; i++) {
            if (vec[i] > 0) continue;
            vec[i] = n % 2;
            n /= 2;
        }
        return v2ll(vec);
    }

    long long v2ll(const vector<int> vec) {
        long long res = 0, curr = 1;
        for (int v : vec) {
            if (v) res += curr;
            curr <<= 1;
        }
        return res;
    }
};