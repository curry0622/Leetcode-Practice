class Solution {
vector<int> dp;
public:
    Solution () {
        dp = vector<int>(59, -1);
        dp[2] = 1;
        dp[3] = 2;
    }

    int integerBreak(int n) {
        if (dp[n] == -1) {
            for (int i = 1; i < n - 1; i++) {
                dp[n] = max(dp[n], i * integerBreak(n - i));
                dp[n] = max(dp[n], i * (n - i));
            }
        }
        return dp[n];
    }
};