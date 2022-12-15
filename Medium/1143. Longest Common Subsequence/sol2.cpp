class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        vector<int> dp = vector<int>(n, 0);

        int prev = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int tmp = getVal(j, dp);
                if(text1[i] == text2[j]) {
                    // dp[i][j] = getVal(i-1, j-1, dp) + 1;
                    dp[j] = (j == 0 ? 0 : prev) + 1;
                } else {
                    // dp[i][j] = max(getVal(i-1, j, dp), getVal(i, j-1, dp));
                    dp[j] = max(getVal(j, dp), getVal(j-1, dp));
                }
                prev = tmp;
            }
        }

        return dp[n-1];
    }

    int getVal(int j, const vector<int>& dp) {
        if(j >= 0 && j < dp.size())
            return dp[j];
        return 0;
    }
};