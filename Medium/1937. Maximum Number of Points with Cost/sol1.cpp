class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int m = points.size(), n = points[0].size();
        long long res = 0;
        vector<long long> dp(n, 0);
        for (int i = 0; i < n; i++) {
            dp[i] = points[0][i];
            res = max(res, dp[i]);
        }
        for (int i = 1; i < m; i++) {
            vector<long long> left(n, 0);
            vector<long long> right(n, 0);
            left[0] = dp[0];
            right[n-1] = dp[n-1];
            for (int j = 1; j < n; j++) {
                left[j] = max(dp[j], left[j-1]-1);
            }
            for (int j = n-2; j >= 0; j--) {
                right[j] = max(dp[j], right[j+1]-1);
            }
            for (int j = 0; j < n; j++) {
                dp[j] = points[i][j] + max(left[j], right[j]);
                res = max(res, dp[j]);
            }
        }
        return res;
    }
};