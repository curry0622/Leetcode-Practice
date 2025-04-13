const long long MOD = 1e9 + 7;
class Solution {
public:
    int countGoodNumbers(long long n) {
        long long cnt5 = (n+1)/2;
        long long cnt4 = n/2;
        return modPower(5, cnt5) * modPower(4, cnt4) % MOD;
    }

    long long modPower(long long base, long long exp, long long mod = MOD) {
        long long result = 1;
        base %= mod;  // ensure base is within mod
        while (exp > 0) {
            if (exp % 2 == 1) {  // if exp is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }
};

// n=1
// 5
// n=2
// 5*4
// n=3
// 5*4*5