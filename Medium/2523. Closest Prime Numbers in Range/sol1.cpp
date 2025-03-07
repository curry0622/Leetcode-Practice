class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false, isPrime[1] = false;
        for (int i = 2; i * i <= right; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> res = {-1, -1};
        vector<int> curr = res;
        int diff = INT_MAX;
        for (int i = right; i >= left; i--) {
            if (isPrime[i]) {
                curr[1] = curr[0];
                curr[0] = i;
                if (curr[0] != -1 && curr[1] != -1 && curr[1] - curr[0] <= diff) {
                    res = curr;
                    diff = curr[1] - curr[0];
                }
            }
        }
        return res;
    }
};