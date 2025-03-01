class Solution {
    public:
        int longestCommonSubsequence(string str1, string str2) {
            int len1 = str1.size(), len2 = str2.size();
            vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
            for (int i = 1; i <= len1; i++) {
                for (int j = 1; j <= len2; j++) {
                    if (str1[i-1] == str2[j-1]) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else {
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                    }
                }
            }
            return dp[len1][len2];
        }
    };

    // dp[i][j] = (1) d[i-1][j-1]+1, if str1[i] == str2[j]
    //          = (2) max(dp[i-1][j], dp[i][j-1]), otherwise