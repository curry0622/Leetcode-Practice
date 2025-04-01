class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);

        dp[n - 1] = questions[n - 1][0];
        long long postMax = dp[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            int pwr = questions[i][1];
            dp[i] = questions[i][0];

            if (i + pwr + 1 < n) {
                dp[i] += dp[i + pwr + 1];
            }

            dp[i] = max(dp[i], postMax);
            postMax = dp[i];

        }

        return postMax;
    }
};
