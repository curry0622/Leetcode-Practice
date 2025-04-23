class Solution {
public:
    int countLargestGroup(int n) {
        int maxFreq = 0;
        unordered_map<int, int> freq;
        for (int i = 1; i <= n; i++) {
            int sum = sumDigits(i);
            freq[sum]++;
            maxFreq = max(maxFreq, freq[sum]);
        }
        int res = 0;
        for (const auto& [key, value] : freq) {
            if (value == maxFreq) res++;
        }
        return res;
    }

    int sumDigits(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }
};