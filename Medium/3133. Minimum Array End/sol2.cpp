class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> res;
        for (int i = 0; x > 0; i++) {
            if (x % 2) res.set(i);
            x /= 2;
        }
        --n;
        for (int i = 0; n > 0; i++) {
            if (res.test(i)) continue;
            if (n % 2) res.set(i);
            n /= 2;
        }
        return res.to_ulong();
    }
};