class Solution {
public:
    const int MOD = 1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sums;
        for (int cnt = 1; cnt <= n; cnt++) {
            for (int i = 0; i <= n - cnt; i++) {
                int sum = 0;
                for (int j = 0; j < cnt; j++) {
                    sum += nums[i+j];
                }
                sums.push_back(sum);
            }
        }
        sort(sums.begin(), sums.end());

        int res = 0;
        for (int i = left - 1; i < right; i++) {
            res += sums[i] % MOD;
            res %= MOD;
        }
        return res;
    }
};