class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for (int num : arr) {
            int i = num % k;
            if (i < 0) i += k;
            freq[i]++;
        }
        if (freq[0] % 2)
            return false;
        for (int i = 1; i <= k / 2; i++) {
            if (freq[i] != freq[k-i]) {
                return false;
            }
        }
        if (k % 2 == 0 && freq[k / 2] % 2)
            return false;
        return true;
    }
};