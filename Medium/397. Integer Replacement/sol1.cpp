class Solution {
using ll = long long;
unordered_map<ll, int> ump;
public:
    int integerReplacement(ll n) {
        if (ump[n] == 0) {
            if (n == 1) {
                ump[n] = 0;
            } else if (n & 1) {
                ump[n] = 1 + min(integerReplacement(n + 1),
                                 integerReplacement(n - 1));
            } else {
                ump[n] = 1 + integerReplacement(n / 2);
            }
        }
        return ump[n];
    }
};