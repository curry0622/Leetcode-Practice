class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9 + 7;
        vector<vector<int>> dp(31, vector<int>(1001, 0));
        for(int i = 1; i <= k; i++) {
            dp[1][i] = 1;
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                for(int m = 1; m <= k; m++) {
                    if(j - m >= 0)
                        dp[i][j] = (dp[i][j] % mod + dp[i - 1][j - m] % mod) % mod;
                }
            }
        }
        return dp[n][target];
    }
};